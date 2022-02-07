#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);

  //[initialize test potentiometer pins]
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  //[int rgb[] = {pot1.value, pot2.value, pot3.value}]
  
  WiFi.begin("nguyen_ohana", "3BBH7473KE");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("waiting for connection");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) Serial.println("error in connecting to wifi"); delay(7500); return;

  //***DO NOT INCLUDE--APP MUST POST REGARDLESS IF QUERY IS NON UNIQUE [if (pot1.value == rgb[0] && pot2.value == rgb[1] && pot3.value == rgb[2]) delay(200); return;]

  //[rgb[] = {pot1.value, pot2.value, pot3.value};]
  //***test--[rgb[] = {random(0, 255), random(0, 255), random(0, 255)};]

  HTTPClient http_post;

  http_post.begin("https://dualcomsv.ryangu23.repl.co/update");
  http_post.addHeader("Content-Type", "application/json");
  
  int httpCode_post = http_post.POST("{[34, 233, 124]}"); //--> int httpCode_post = http_post.POST(String(rgb[]));
  String payload_post = http_post.getString();

  Serial.println(httpCode_post); //post response???
  Serial.println(payload_post); //post request summary/dossier???

  http_post.end();

  //***not needed after server modification
  //HTTPClient http_get;

  //http_get.begin("https://dualcomsv.ryangu23.repl.co/retinfo");
  //http_get.addHeader("Content-Type", "application/json");

  //int httpCode_get = http_get.GET();

  //if (httpCode_get > 0) {
    //String payload_get = http_get.getString();
    //Serial.println(payload_get);
  //}
  
  //http_get.end();

  delay(500);
}
