main: main.o insert_list.o read_number_option.o show_main_menu.o wificollector_collect.o wificollector_quit.o show_wifi_one_network.o wificollector_sort.o
	gcc -o main main.o wificollector_collect.o show_main_menu.o wificollector_quit.o read_number_option.o insert_list.o show_wifi_one_network.o wificollector_sort.o

wificollector_collect.o: wificollector_collect.c 
	gcc -g -c wificollector_collect.c 

wificollector_quit.o: wificollector_quit.c 
	gcc -c wificollector_quit.c 

read_number_option.o: read_number_option.c 
	gcc -c read_number_option.c 

show_main_menu.o: show_main_menu.c
	gcc -c show_main_menu.c 

insert_list.o: insert_list.c wificollector_collect.o
	gcc -g -c insert_list.c

wificollector_sort.o: wificollector_sort.c 
	gcc -g -c wificollector_sort.c 

show_wifi_one_network.o: show_wifi_one_network.c 
	gcc -g -c show_wifi_one_network.c

main.o: main.c insert_list.o read_number_option.o show_main_menu.o wificollector_collect.o wificollector_quit.o show_wifi_one_network.o wificollector_sort.o
	gcc -g -c main.c 

