all:
	cd Week4 && $(MAKE) all
	cd Week5 && $(MAKE) all
	cd Week6 && $(MAKE) all
	cd Week7 && $(MAKE) all
	cd Week8 && $(MAKE) all
	cd Week9 && $(MAKE) all
	cd Week10 && $(MAKE) all

clean:
	cd Week4 && rm *.o
	cd Week5 && rm *.o
	cd Week6 && rm *.o
	cd Week7 && rm *.o
	cd Week8 && rm *.o
	cd Week9 && rm *.o
	cd Week10 && rm *.o
