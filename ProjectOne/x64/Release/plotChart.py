import pandas as pd
import matplotlib.pyplot as plt

def plot_column_trend(csv_file, column_index):
    try:
        # Load data from the CSV file
        data = pd.read_csv(csv_file, delimiter=';')

        # Check if the column index is valid
        if column_index < 0 or column_index >= len(data.columns):
            print(f"Error: The provided column index ({column_index}) is out of range.")
            print(f"Available indices: 0 - {len(data.columns) - 1}")
            return

        # Get the column name
        column_name = data.columns[column_index]

        # Define the X-axis as a range of integers starting from 0
        x_axis = range(len(data[column_name]))

        # Create a plot for the selected column
        plt.figure()
        plt.plot(x_axis, data[column_name], marker='o', label=column_name)
        plt.title(f"{column_name} trend over time")
        plt.xlabel("Number of rounds")
        plt.ylabel("Value")
        plt.legend()
        plt.grid(True)
        plt.show()  # Display the plot in a window
        print(f"Plot for column '{column_name}' has been generated.")
    except Exception as e:
        print(f"Error while generating the plot: {e}")

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 3:
        print("Usage: python draw_plots.py <csv_file> <column_index>")
    else:
        try:
            # Get the file name and column index
            csv_file = sys.argv[1]
            column_index = int(sys.argv[2])  # Convert to an integer
            plot_column_trend(csv_file, column_index)
        except ValueError:
            print("Error: Column index must be an integer.")
