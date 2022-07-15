OBJECTS = build/loader.o 		\
		  build/kmain.o  		\
		  build/io.o 	 		\
		  build/fb.o 	 		\
		  build/serial.o 		\
		  build/interrupt.o 	\
		  build/interrupt_asm.o \
		  build/pic.o			\
		  build/keyboard.o		\
		  build/idt.o			\
		  build/idt_asm.o
CC = gcc
CFLAGS = -m32 -nostdlib -fno-builtin -fno-stack-protector \
		 -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: build/kernel.elf

build/kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o build/kernel.elf

os.iso: build/kernel.elf
	cp build/kernel.elf build/iso/boot/kernel.elf
	genisoimage -R								  \
				-b boot/grub/stage2_eltorito	  \
				-no-emul-boot					  \
				-boot-load-size 4				  \
				-A os							  \
				-input-charset utf8				  \
				-quiet							  \
				-boot-info-table				  \
				-o build/os.iso					  \
				build/iso

run: os.iso
	qemu-system-i386 -cdrom build/os.iso -serial stdio

build/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

build/%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf build/*.o build/kernel.elf build/os.iso