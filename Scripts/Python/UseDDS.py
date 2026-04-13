import os
import sys
import subprocess

def replace_png_with_dds(input_file, output_file=None):
    if not os.path.isfile(input_file):
        print(f"Error: The file '{input_file}' does not exist.")
        return

    with open(input_file, 'r') as file:
        content = file.read()

    updated_content = content.replace('.png', '.dds').replace('.jpg', '.dds')

    if output_file is None:
        output_file = input_file

    with open(output_file, 'w') as file:
        file.write(updated_content)

    print(f"Replacements completed. Updated file saved as '{output_file}'.")

def convert_textures_in_directory(input_dir, output_dir = None):
    if not os.path.exists(input_dir):
        print(f"Error: The input directory '{input_dir}' does not exist.")
        sys.exit(1)

    if output_dir is None:
        output_dir = input_dir
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    for file_name in os.listdir(input_dir):
        input_file = os.path.join(input_dir, file_name)

        if file_name.endswith(('.png', '.jpg')):
            print(f"Processing {input_file}...")

            file = r"D:\Projects\C++\2425-Y2B-PR-233499\code\Scripts\Bat\NV\nvcompress.exe"

            arguments = ["-bc7", "-min-mip-size", "4", input_file]

            subprocess.run([file] + arguments, check=True)

    print("All textures processed.")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python script.py <input_file> [output_file]")
        sys.exit(1)

    input_file_path = os.path.abspath(sys.argv[1])
    output_file_path = os.path.abspath(sys.argv[2]) if len(sys.argv) > 2 else None

    input_directory = os.path.dirname(input_file_path)
    output_directory = os.path.dirname(output_file_path) if output_file_path else input_directory

    replace_png_with_dds(input_file_path, output_file_path)
    convert_textures_in_directory(input_directory, output_directory)