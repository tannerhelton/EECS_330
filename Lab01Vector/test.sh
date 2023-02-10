g++ -std=c++11 MainTest.cpp -o Lab1 &&
for i in {0..9}; do
    ./Lab1 "Inputs/input_$i.txt" > "result_$i.txt"
done

for i in {0..9}; do
    python3 GradingScript.py "result_$i.txt" "Outputs/output_$i.txt"
    rm "result_$i.txt"
done

rm Lab1 test_result