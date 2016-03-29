# production
rule-app.out: app.c
	gcc app.c -o app.out
run: rule-app.out islandNames.txt
	./app.out < islandNames.txt
# debug  
rule-app.debug: app.c
	gcc -g app.c -o app.debug
run-debug: rule-app.debug islandNames.txt
	valgrind --leak-check=full ./app.debug <islandNames.txt