enum Types{
    REQUEST,
    RESPONSE
};

struct Request{
    int32_t type;//4 bytes
};

struct Payload{                 //              44 bytes:
    int32_t type;               //              4 bytes
    int32_t numberOfResistors;  //0-20          4 bytes
    float usefulVoltage;        //              4 bytes
    float usefulAmperage;       //              4 bytes
    float ballastVoltage;       //              4 bytes
    float ballastAmperage;      //              4 bytes
    bool currentValues[20];     //0-off 1-on    20 bytes
};

//template receive function. Usage: receive<piece_data>() or receive<int32_t> - would work
template<typename T>
T receive(){
  T result;
  Serial.readBytes((char*)&result, sizeof(T));
  return result;
}

Payload payload{
  RESPONSE,
  3,
  3.31,
  7.56,
  8.24,
  1.11,
  {1,0,1}
  };

void  setup() {
    Serial.begin(9600);
}

void loop() {
    if(Serial.available()!=0){
      receive<Request>();
      Serial.write((char*)&payload,sizeof(Payload));
      }
}
