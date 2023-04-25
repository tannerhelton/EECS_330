g++ -std=c++11 MainTest.cpp -o Lab &&
./Lab "input.txt" > "result.txt" &&
diff "result.txt" "Outputs/output_0.txt" | grep "^>" | wc -l
# python3 GradingScript.py "result.txt" "Outputs/output_0.txt"
# rm "result_0.txt"

# rm Lab test_result