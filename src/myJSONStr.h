/**
 * @file myJSONStr.h
 * @brief 
 * 
 */

#ifndef MYJSONSTR_H
#define MYJSONSTR_H

// {
//   "id": "hostanme",
//   "topic": "tpois/topic",
//   "status": "driving",
//   "sector": "transit",
//   "line": 1,
//   "ack":"hostname",
//   "req":"hostname",
//   "cargo":"gemuse",
//   "token":false;
//   "error":false
// }

struct myJSONStr {
    String id = "-1";
    String topic = "-1";
    String status = "-1";
    String sector = "-1";
    int line = -1;
    String ack = "-1";
    String req = "-1";
    String cargo = "-1";
    bool token = false;
    bool error = false;
};
#endif