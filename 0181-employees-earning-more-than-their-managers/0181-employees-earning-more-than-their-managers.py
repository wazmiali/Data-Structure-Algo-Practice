import pandas as pd

def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    # Perform a self-join to compare employees with their managers
    merged = pd.merge(
        employee, employee,
        left_on='managerId', right_on='id',
        suffixes=('', '_manager')
    )

    # Filter employees whose salary is greater than their manager's salary
    result = merged[merged['salary'] > merged['salary_manager']]

    # Select only the employee names for the output
    result = result[['name']]
    result.columns = ['Employee']

    return result

# Example Input
employee_data = {
    "id": [1, 2, 3, 4],
    "name": ["Joe", "Henry", "Sam", "Max"],
    "salary": [70000, 80000, 60000, 90000],
    "managerId": [3, 4, None, None]
}

employee_df = pd.DataFrame(employee_data)

# Output
output = find_employees(employee_df)
print(output)
