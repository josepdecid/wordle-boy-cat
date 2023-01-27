C:\gbdk\bin\lcc -debug -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o main.o src/*.c

C:\gbdk\bin\lcc -debug -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o WordleBoyCat.gb main.o

del *.asm *.lst *.sym *.adb *.ihx *.noi *.cdb *.map *.o