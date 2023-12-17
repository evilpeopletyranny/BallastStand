#ifndef DATA_PAYLOAD_H
#define DATA_PAYLOAD_H



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

#endif // DATA_PAYLOAD_H
