all:
	gcc 200-mindreader.c -std=gnu99 -o 200-mindreader
	gcc 100-camping.c -static -std=gnu99 -o 100-camping
	upx --ultra-brute 100-camping
	gcc 300-jmping_for_joy.c -std=gnu99 -o 300-jmping_for_joy

clean:
	rm -f 100-camping
	rm -f 200-mindreader
	rm -f 300-jmping_for_joy
