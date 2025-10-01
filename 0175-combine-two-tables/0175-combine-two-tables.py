import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    # Merge the two tables with a left join on personId
    result = pd.merge(person, address, on='personId', how='left')
    
    # Select and rearrange columns as per the expected output
    result = result[['firstName', 'lastName', 'city', 'state']]
    
    return result

# Example Input
person_data = {
    "personId": [1, 2],
    "lastName": ["Wang", "Alice"],
    "firstName": ["Allen", "Bob"]
}
address_data = {
    "addressId": [1, 2],
    "personId": [2, 3],
    "city": ["New York City", "Leetcode"],
    "state": ["New York", "California"]
}

person_df = pd.DataFrame(person_data)
address_df = pd.DataFrame(address_data)

# Output
output = combine_two_tables(person_df, address_df)
print(output)
