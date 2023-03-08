first: MyQueue_t984h395.h MyStack_t984h395.h
	@clear
	@g++ -std=c++11 MainTest.cpp -o my_program
	@./my_program Inputs/input_0.txt >result.txt
	@python3 GradingScript.py result.txt Outputs/output_0.txt
	@make clean

test: main perms
	@./test.sh

valgrindtest: main perms
	@./valgrindTest.sh

perms:
	@chmod +x test.sh valgrindTest.sh

clean:
	@rm -f my_program result.txt

main: MainTest.cpp *.h
	@g++ -std=c++11 MainTest.cpp -o my_program