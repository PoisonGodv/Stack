//
// Created by lnw on 2021/10/25.
//

#ifndef STACK01_ELEMTYPE_H
#define STACK01_ELEMTYPE_H
/*
 * 停车时间不超过一天，用24小时
 */
typedef struct {
    int hour,min;
}time;
typedef struct {
    time time1;
    int carNumber;
}Elemtype;
#endif //STACK01_ELEMTYPE_H
