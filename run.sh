

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# Clean and build
echo "Cleaning and building..."
make clean
make

# Create output directory
mkdir -p outputs

# Counter for passed/failed tests
passed=0
failed=0

# Run all test cases
for test_file in testcases/*.in; do
    test_name=$(basename "$test_file" .in)
    expected_output="testcases/${test_name}.out"
    actual_output="outputs/${test_name}.out"
    
    echo "Running test: ${test_name}"
    ./program < "$test_file" > "$actual_output"
    
    if [ -f "$expected_output" ]; then
        if diff -w "$expected_output" "$actual_output" > /dev/null; then
            echo -e "${GREEN}✓ Test ${test_name} passed${NC}"
            ((passed++))
        else
            echo -e "${RED}✗ Test ${test_name} failed${NC}"
            echo "Diff output:"
            diff -w "$expected_output" "$actual_output"
            ((failed++))
        fi
    else
        echo "Warning: No expected output file for ${test_name}"
    fi
done

# Print summary
echo
echo "Test Summary:"
echo -e "${GREEN}Passed: ${passed}${NC}"
echo -e "${RED}Failed: ${failed}${NC}"
echo "Total: $((passed + failed))"
if((failed == 0)); then
    echo -e "${GREEN}All tests passed!${NC}"
else
    echo -e "${RED}${failed} tests failed.${NC}"
fi

# Exit with failure if any tests failed
[ "$failed" -eq 0 ]