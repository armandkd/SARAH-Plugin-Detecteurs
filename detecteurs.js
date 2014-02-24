exports.action = function(data, callback, config, SARAH) {
  console.log('Detecteur enclenché : ' + data.code);
  callback({'tts': 'Code reçu : ' + data.code});
}