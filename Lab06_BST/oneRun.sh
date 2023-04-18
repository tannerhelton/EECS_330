g++ -std=c++11 MainTest.cpp -o Lab &&
./Lab "Inputs/input_0.txt" > "result_0.txt"
python3 GradingScript.py "result_0.txt" "Outputs/output_0.txt"
# rm "result_0.txt"

rm Lab test_result