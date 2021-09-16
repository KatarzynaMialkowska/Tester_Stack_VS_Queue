
.SUFFIXES: .cxx .o .x .hxx
NAME1 = stack
NAME2 = queue
NAME3 = generator
NAME4 = generator_overflow
NAME5 = generator_underflow
NAME6 = stdstack
NAME7 = stdqueue

CXX1 = $(NAME1).cxx
CXX2 = $(NAME2).cxx
CXX3 = $(NAME3).cxx
CXX4 = $(NAME4).cxx
CXX5 = $(NAME5).cxx
CXX6 = $(NAME6).cxx
CXX7 = $(NAME7).cxx

EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
EXEC4 = $(NAME4).x
EXEC5 = $(NAME5).x
EXEC6 = $(NAME6).x
EXEC7 = $(NAME7).x

CO=g++
FLAGS= -std=c++11


.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5) $(EXEC6) $(EXEC7)


$(EXEC1):
	$(CO) -o $@ $(CXX1) $(FLAGS) 

$(EXEC2): 
	$(CO) -o $@ $(CXX2) $(FLAGS)

$(EXEC3):
	$(CO) -o $@ $(CXX3) $(FLAGS) 

$(EXEC4):
	$(CO) -o $@ $(CXX4) $(FLAGS) 

$(EXEC5):
	$(CO) -o $@ $(CXX5) $(FLAGS) 
	
$(EXEC6):
	$(CO) -o $@ $(CXX6) $(FLAGS) 

$(EXEC7):
	$(CO) -o $@ $(CXX7) $(FLAGS) 


##TESTER##
#STACK#
#test 1 -  comparison stack with std::stack, random data#
stest1: $(EXEC1) $(EXEC3) $(EXEC6)

.PHONY: test_stack_1
test_stack_1: stest1
	@echo "\n(I)\n*STACK vs STD::STACK*\nRANDOM DATA\n"
	@./$(EXEC3) > test1.txt
	@echo "\n*testing own stack. wait...*\n"
	@time ./$(EXEC1) < test1.txt > stack1.txt
	@echo "\n*testing std::stack. wait...*\n"
	@time ./$(EXEC6) < test1.txt > stdstack1.txt
	@echo "\n*output file:*\n"
	@diff -s stack1.txt stdstack1.txt

#test 2 - comparison stack with std::stack, the given number of operations#
.PHONY: test_stack_2
test_stack_2: stest1
	@echo "\n(II)\n*STACK vs STD::STACK*\nDEFINED NUMBER OF OPERATIONS\n"
	@./$(EXEC3) 100 > test2.txt 
	@echo "\n*testing own stack. wait...*\n"
	@time ./$(EXEC1) < test2.txt > stack2.txt
	@echo "\n*testing std::stack. wait...*\n"
	@time ./$(EXEC6) < test2.txt > stdstack2.txt
	@echo "\n*output file:*\n"
	diff -s stack2.txt stdstack2.txt

#test 3 - comparison stack with std::stack when overflow occurs#
stest2: $(EXEC1) $(EXEC4) $(EXEC6)
.PHONY: test_stack_3
test_stack_3: stest2
	@echo "\n(III)\n*STACK vs STD::STACK*\nBUFFER OVERFLOW TEST\n"
	./$(EXEC4) 1000001 > test3.txt
	@echo "\n*testing own stack. wait...*\n"
	@time ./$(EXEC1) < test3.txt > stack3.txt
	@echo "\n*testing std::stack. wait...*\n"
	@time ./$(EXEC6) < test3.txt > stdstack3.txt
	@echo "\n*output file:*\n"
	diff -s stack3.txt stdstack3.txt
	
#test 4 - comparison stack with std::stack when underflow occurs#
stest3: $(EXEC1) $(EXEC5) $(EXEC6)
.PHONY: test_stack_4
test_stack_4: stest3
	@echo "\n(IV)\n*STACK vs STD::STACK*\nTEST OPERATION OF POP() FOR EMPTY BUFFER\n"
	@./$(EXEC5) > test4.txt
	@echo "\n*testing own stack. wait...*\n"
	@time ./$(EXEC1) < test4.txt > stack4.txt
	@echo "\n*testing std::stack. wait...*\n"
	@time ./$(EXEC6) < test4.txt > stdstack4.txt
	@echo "\n*output file:*\n"
	diff -s stack4.txt stdstack4.txt

#QUEUE#
#test 1 - comparison queue with std::queue, random data#
qtest1: $(EXEC2) $(EXEC3) $(EXEC7)

.PHONY: test_queue_1
test_queue_1: qtest1
	@echo "\n(I)\n*QUEUE vs STD::QUEUE*\nRANDOM DATA\n"
	@ ./$(EXEC3) > test1.txt
	@echo "\n*testing own queue. wait...*\n"
	@time ./$(EXEC2) < test1.txt > queue1.txt
	@echo "\n*testing std::queue. wait...*\n"
	@time ./$(EXEC7) < test1.txt > stdqueue1.txt
	@echo "\n*output file:*\n"
	diff -s queue1.txt stdqueue1.txt

#test 2 - comparison queue with std::queue, the given number of operations#
.PHONY: test_queue_2
test_queue_2: qtest1
	@echo "\n(II)\n*QUEUE vs STD::QUEUE*\nDEFINED NUMBER OF OPERATIONS\n"
	@./$(EXEC3) 100 > test2.txt
	@echo "\n*testing own queue. wait...*\n"
	@time ./$(EXEC2) < test2.txt > queue2.txt
	@echo "\n*testing std::queue. wait...*\n"
	@time ./$(EXEC7) < test2.txt > stdqueue2.txt
	@echo "\n*output file:*\n"
	diff -s queue2.txt stdqueue2.txt

#test 3 - comparison queue with std::queue when overflow occurs#
qtest2: $(EXEC2) $(EXEC4) $(EXEC7)
.PHONY: test_queue_3
test_queue_3: qtest2
	@echo "\n(III)\n*QUEUE vs STD::QUEUE*\nBUFFER OVERFLOW TEST\n"
	@./$(EXEC4) 1000001 > test3.txt
	@echo "\n*testing own queue. wait...*\n"
	@time ./$(EXEC2) < test3.txt > queue3.txt
	@echo "\n*testing std::queue. wait...*\n"
	@time ./$(EXEC7) < test3.txt > stdqueue3.txt
	@echo "\n*output file:*\n"
	diff -s queue3.txt stdqueue3.txt

#test 4 - comparison queue with std::queue when underflow occurs#
qtest3: $(EXEC2) $(EXEC5) $(EXEC7)
.PHONY: test_queue_4
test_queue_4: qtest3
	@echo "\n(IV)\n*QUEUE vs STD::QUEUE*\nTEST OPERATION OF POP() FOR EMPTY BUFFER\n"
	@./$(EXEC5) > test4.txt
	@echo "\n*testing own queue. wait...*\n"
	@time ./$(EXEC2) < test4.txt > queue4.txt
	@echo "\n*testing std::queue. wait...*\n"
	@time ./$(EXEC7) < test4.txt > stdqueue4.txt
	@echo "\n*output file:*\n"
	diff -s queue4.txt stdqueue4.txt


##ALL TESTS##
.PHONY: test
test: test_stack_1 test_stack_2 test_stack_3 test_stack_4 test_queue_1 test_queue_2 test_queue_3 test_queue_4


.PHONY: clean
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x *.txt core core* a.out; rm -rf ${LIB_DIR}