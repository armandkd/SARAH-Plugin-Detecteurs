SARAH-Plugin-Detecteurs
=======================

SARAH 433MHz motion detector plugin  
I have also included the C++ code I used.  
The javascript is very short, the whole point is just to trigger a rule like :  

```javascript
var date = new Date();
options.id="0";
options.declencheur="1";
options.tmp=true
if (date.getHours() > 18 || date.getHours() < 8) {
  if (options.code=="5139785") {
    options.id="du salon";
    options.etat="1";
  }
}