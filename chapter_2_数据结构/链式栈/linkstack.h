/*
@ 链式栈
*/

#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef void LinkStack;

LinkStack* LinkStack_Create();

void LinkStack_Destroy(LinkStack* stack);

void LinkStack_Clear(LinkStack* stack);

int LinkStack_Push(LinkStack* stack, void* item);

void* LinkStack_Pop(LinkStack* stack);

void* LinkStack_Top(LinkStack* stack);

int LinkStack_Size(LinkStack* stack);

#endif //_MY_LINKSTACK_H_

