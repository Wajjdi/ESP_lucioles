#include <ArduinoJson.h>

/*========================================================*/
float lat =1.7116483;
float lgn =10.2821685;
String getJSONString_fromlocation(float lat, float lgn){
  StaticJsonDocument<1000> jsondoc;
  jsondoc["lat"] = lat;
  jsondoc["lgn"] = lgn;
  String data = "";
  serializeJson(jsondoc, data);
  return data;
}
String get_uptime() {
  String s = (String)(esp_log_timestamp()/1000);
  Serial.println("ok");
  Serial.println("uptime : "+s);
  return s;
}
String getJSONString_fromstatus(float temp, int light){
  /*
   * put all relevant data from esp in a "json formatted" String
   */
  StaticJsonDocument<1000> jsondoc;
  jsondoc["status"]["temperature"] = temp;
  jsondoc["status"]["light"] = light;
  //jsondoc["status"]["ledCooler"] = "";
  //jsondoc["status"]["ledHeater"] = "";
  //  jsondoc["status"]["running"] = "";

  jsondoc["info"]["loc"] = getJSONString_fromlocation(lat, lgn);
  jsondoc["info"]["user"] = "lg802804";
  //jsondoc["info"]["uptime"] = get_uptime();
  jsondoc["info"]["ssid"] = String(WiFi.SSID());
  jsondoc["info"]["ident"] =  String(WiFi.macAddress());
  jsondoc["info"]["ip"] =WiFi.localIP().toString();

 /*jsondoc["reporthost"]["target_ip"] = "";
    jsondoc["reporthost"]["target_port"] = "";
  jsondoc["reporthost"]["sp"] = "";
  
  jsondoc["regul"]["threshold"] = DAY_LIGHT;
  jsondoc["regul"]["sbn"] = TEMP_NIGHT_LOW;
  jsondoc["regul"]["shn"] = TEMP_NIGHT_HIGH;
  jsondoc["regul"]["sbj"] = TEMP_DAY_LOW;
  jsondoc["regul"]["shj"] = TEMP_DAY_HIGH;
  */
  String data = "";
  serializeJson(jsondoc, data);
  return data;
}
