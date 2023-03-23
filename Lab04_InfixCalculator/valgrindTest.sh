g++ -std=c++11 MainTest.cpp -o my_program

for i in {0..9}; do
    valgrind --leak-check=full ./my_program "Inputs/input_$i.txt" > "result_$i.txt"
done

for i in {0..9}; do
    python3 GradingScript.py "result_$i.txt" "Outputs/output_$i.txt"
    rm "result_$i.txt"
done

rm test_result
