g++ -std=c++11 MainTest.cpp -o Lab &&

echo "Old test cases:"

for i in {0..9}; do
    ./Lab "OLD_Inputs/input_$i.txt" > "result_$i.txt"
done

for i in {0..9}; do
    python3 GradingScript.py "result_$i.txt" "OLD_Outputs/output_$i.txt"
    rm "result_$i.txt"
done

echo "New test cases:"

for i in {0..9}; do
    ./Lab "NEW_Inputs/input_$i.txt" > "result_$i.txt"
done

for i in {0..9}; do
    python3 GradingScript.py "result_$i.txt" "NEW_Outputs/output_$i.txt"
    rm "result_$i.txt"
done

rm Lab test_result