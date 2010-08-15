INSTALL_DIR=/usr

all:

install: arrayqueue.h
	cp -f arrayqueue.h $(INSTALL_DIR)/include/

clean:
