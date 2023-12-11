import os

def rename_files(folder_path):
    # Get a list of all files in the folder
    files = os.listdir(folder_path)

    for filename in files:
        # Construct the new filename (modify this logic based on your needs)
        filename_split = filename.split('-')
        new_filename = '-'.join(filename_split[:-1]) + '.jar'
        # print(f"new_filename :{new_filename}")
        # Create the full file paths
        old_path = os.path.join(folder_path, filename)
        new_path = os.path.join(folder_path, new_filename)

        # Rename the file
        os.rename(old_path, new_path)
        print(f'Renamed: {filename} -> {new_filename}')




def main():
    # Provide the path to the folder containing the files
    folder_path = '/mnt/d/ShareFolder/confluence/atlassian-confluence-7.19.17/atlassian-confluence-7.19.17/confluence/WEB-INF/atlassian-bundled-plugins'
    rename_files(folder_path)

if __name__ == "__main__":
    main()