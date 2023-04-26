void handleRoot()                                         //handle function: send webpage to client
{
  server.send(200,"text/html", webpageCont);              // Used To Sends An Http Response Back To The Client With The Specified Status Code, Content Type, And Content.
}

//=========================================================================================================================================================================
//function process event: new data received from client (its a callback function that is called by the WebSocketsServer library when a WebSocket event occurs.)
//"num" is an identifier for the WebSocket client that triggered the event
//"type" is the type of the event (e.g. WStype_TEXT for a text message)
//"payload" is a pointer to the message data
//"welength" is the length of the message data in bytes.
//=========================================================================================================================================================================
void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t welength)
{
  String payloadString = (const char *)payload;          // Used To converts a byte array (i.e., payload) into a String object (i.e., payloadString).
//=========================================================================================================================================================================
  if(type == WStype_TEXT)                                // Used To checks whether the WebSocket event type is a text message (WStype_TEXT). If it is, then the code within the curly braces is executed.
  {
    byte separator=payloadString.indexOf('=');           // Used To finds the index of the equals sign (=) in the payloadString. The equals sign is used as a separator between the key and value in the key-value pairs.
    String var = payloadString.substring(0,separator);   // Used To extracts the substring of the payloadString from the beginning of the string to the index of the separator. This substring represents the key in the key-value pair.
    String val = payloadString.substring(separator+1);   // Used To extracts the substring of the payloadString from the index of the separator plus one to the end of the string. This substring represents the value in the key-value pair.
//=========================================================================================================================================================================
    if(var == "RELAYonoff")                              // Used To check whether the key extracted from the payload is equal to the string. If it is, then the code within the curly braces is executed.
    {
      RELAYonoff = false;                                // Used To set the relay off variable to false by default. This variable is used to track whether the relay is turned on or off.
      if(val == "ON") RELAYonoff = true;                 // Used To check whether the value extracted from the payload is equal to the string "ON". If it is, then the relay variable is set to true, indicating that the relay should be turned on.
    }
  }
}