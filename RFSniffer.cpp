#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <unistd.h>



RCSwitch mySwitch;
// RAII cleanup
curlpp::Cleanup myCleanup;
// standard request object.
curlpp::Easy myRequest;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

int main(int argc, char *argv[]) {
     int PIN = 2;
     if(wiringPiSetup() == -1)
       return 0;
     mySwitch = RCSwitch();
     mySwitch.enableReceive(PIN);  // Receiver on inerrupt 0 => that is pin #2
     while(1) {
      if (mySwitch.available()) {
        int value = mySwitch.getReceivedValue();
        if (value == 0) {
          printf("Unknown encoding");
        } else {
          // Set the URL.
          myRequest.setOpt(new curlpp::options::Url(std::string("http://127.0.0.1:8080/sarah/detecteurs?code=" + patch::to_string(value) )));
          // Send request and get a result.
          myRequest.perform();
          printf("%d\n", value);
          sleep(5);
        }
        mySwitch.resetAvailable();
      }
     sleep(1);
     }
  exit(0);
}
