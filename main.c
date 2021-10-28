#include <stdio.h>
#include "SequenceStack.h"
#include "Stack.h"
#include "Queue.h"

int SSearchByCarId(sequencestack sequencestack1,int carnumber);
int ArrayQueue(queue_head head);
int main() {
    //停车场
    sequencestack park;
    InitSStack(&park);
    //等候便道
    queue_head wait;
    InitQueue(&wait);
    //出场栈
    linkstack leave;
    InitStack(&leave);
    int choiceFlag = 1;//循环控制
    while (choiceFlag){
        puts("请选择到达或者离去,1为到达，2为离去,3退出程序\n");
        int getOrLeaveChoice;
        scanf("%d",&getOrLeaveChoice);
        switch (getOrLeaveChoice) {
            case 1 :
                if(SIsFull(park) == 1){
                    Elemtype elemtype;
                    puts("请输入车牌号");
                    scanf("%d",&(elemtype.carNumber));
                    puts("请输入到达时");
                    scanf("%d",&(elemtype.time1.hour));
                    puts("请输入到达分");
                    scanf("%d",&(elemtype.time1.min));
                    SPush(&park,elemtype);
                    printf("车辆在车库中的位置是%d",park.top);
                } else{//进入等候便道
                    Elemtype elemtype;
                    puts("请输入车牌号");
                    scanf("%d",&(elemtype.carNumber));
                    elemtype.time1.min = 0;
                    elemtype.time1.hour = 0;
                    EnterQueue(&wait,elemtype);
                    int waitNumber;
                    waitNumber = ArrayQueue(wait);
                    printf("车辆在便道中的位置是%d",waitNumber);
                }
                break;
            case 2:
                //按名从车库查找，查一次入队一次
                puts("出车库");
                time time1;//目前时间;
                puts("目前时");
                scanf("%d", &time1.hour);
                puts("目前分");
                scanf("%d", &time1.min);
                puts("输入离去车牌信息");
                int carnumber,place;
                scanf("%d",&carnumber);
                Elemtype elemtype;
                place = SSearchByCarId(park,carnumber);
                if(place == -1)
                    puts("车辆不在车库");
                else{
                    printf("出场车辆为%d,停车时间为%d小时,%d分",park.data[place].carNumber, abs(time1.hour-park.data[place].time1.hour),abs(time1.min-park.data[place].time1.min));
                    for (int i = place; i < park.top;) {
                        SPop(&park,&elemtype);
                        Push(&leave,elemtype);
                    }
                    SPop(&park,&elemtype);
                    while (LinkStackIsEmpty(leave) != 1){
                        Pop(&leave,&elemtype);
                        SPush(&park,elemtype);
                    }
                    DeleteQueue(&wait,&elemtype);
                    elemtype.time1 = time1;
                    SPush(&park,elemtype);
                }
                break;
            case 3:
                choiceFlag = 0;
                break;
            default:
                puts("输入有误");
        }
    }
    return 0;
}
int SSearchByCarId(sequencestack sequencestack1,int carnumber){//顺序栈按名查找，返回栈的下标,-1为不在车库中
    while (sequencestack1.top >-1){
        if(sequencestack1.data[sequencestack1.top].carNumber == carnumber){
            return sequencestack1.top;
        }
        sequencestack1.top--;
    }
    return -1;
}
int ArrayQueue(queue_head head){
    int waitNumber = 0;
    while (head.head->next!=NULL){
        head.head = head.head->next;
        waitNumber++;
    }
    return waitNumber;
}

