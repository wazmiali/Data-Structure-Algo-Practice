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

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    # Drop duplicate salaries and sort them in descending order
    sorted_salaries = employee['salary'].drop_duplicates().sort_values(ascending=False)

    # Get the second highest salary or return None if it doesn't exist
    second_highest = sorted_salaries.iloc[1] if len(sorted_salaries) > 1 else None

    # Create the result DataFrame
    result = pd.DataFrame({'SecondHighestSalary': [second_highest]})

    return result

# Example Input for find_employees
employee_data = {
    "id": [1, 2, 3, 4],
    "name": ["Joe", "Henry", "Sam", "Max"],
    "salary": [70000, 80000, 60000, 90000],
    "managerId": [3, 4, None, None]
}

employee_df = pd.DataFrame(employee_data)

# Output for find_employees
output = find_employees(employee_df)
print(output)

# Example Input for second_highest_salary
salary_data = {
    "id": [1, 2, 3],
    "salary": [100, 200, 300]
}

salary_df = pd.DataFrame(salary_data)

# Output for second_highest_salary
second_highest_output = second_highest_salary(salary_df)
print(second_highest_output)
