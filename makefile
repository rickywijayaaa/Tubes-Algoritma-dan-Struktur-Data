all: run clean

test: main.c Source/ADT/ADT_Mesin-Kata/mesinkata.c Source/ADT/ADT_MesinKarakter/mesinkarakter.c Source/ADT/ADT_List/liststatis.c Source/ADT/ADT_List/listdinamis.c Source/ADT/ADT_LinkedList/listb.c Source/ADT/ADT_Detail/isilagu.c Source/ADT/ADT_Set/set.c Source/ADT/ADT_Map/map.c Source/ADT/ADT_Queue/circular_queue.c Source/command/console.c Source/ADT/ADT_Stack/stack.c  Source/command/play.c Source/command/load.c
	gcc -o main main.c Source/ADT/ADT_Mesin-Kata/mesinkata.c Source/ADT/ADT_MesinKarakter/mesinkarakter.c Source/ADT/ADT_List/liststatis.c Source/ADT/ADT_List/listdinamis.c Source/ADT/ADT_LinkedList/listb.c Source/ADT/ADT_Detail/isilagu.c Source/ADT/ADT_Set/set.c Source/ADT/ADT_Map/map.c Source/ADT/ADT_Queue/circular_queue.c Source/command/console.c Source/ADT/ADT_Stack/stack.c Source/command/play.c Source/command/load.c Source/command/start.c

run: test
	./main.exe

clean:
	del main.exe