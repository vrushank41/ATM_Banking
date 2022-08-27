atm.exe : client.o login.o create.o change.o deposit.o withdraw.o balance.o statement.o total_balance.o
	gcc client.o login.o create.o change.o deposit.o withdraw.o balance.o statement.o total_balance.o -o atm.exe

client.o : client.c atm.h
	gcc -c client.c

login.o : login.c atm.h
	gcc -c login.c

create.o : create.c atm.h
	gcc -c create.c

change.o : change.c atm.h
	gcc -c change.c

deposit.o : deposit.c atm.h
	gcc -c deposit.c

withdraw.o : withdraw.c atm.h
	gcc -c withdraw.c

balance.o : balance.c atm.h
	gcc -c balance.c

statement.o : statement.c atm.h
	gcc -c statement.c

total_balance.o : total_balance.c atm.h
	gcc -c total_balance.c