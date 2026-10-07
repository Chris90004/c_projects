#!/usr/bin/env bash

compiler="${CC:-cc}"
build_dir="build"

red='\033[0;31m'
reset='\033[0m'
checked=0
successful=0
failed=0

# TODO: create the build directory.

mkdir -p build

# TODO: Check whether any .c files exist.

found_source=false

while IFS= read -r -d '' source_file; do
	found_source=true

	# TODO: Get the filename without "./".
	filename="${source_file#./}"

	# TODO: Remove the .c extension.
	program_name="${filename%.c}"

	# TODO: Create the output path.
	output_file="$build_dir/$program_name"

	echo "Compiling: $filename"

	# TODO: Compile the source file.

	if "$compiler" -std=c2x -Wall -Wextra "$source_file" -o "$output_file"; then
		echo "SUCESS: $filename -> $output_file"

		# TODO: Increase successful.

		((successful++))

	else
		echo "FAILURE: $filename"

		#TODO: Increase failed.

		((failed++))

	fi

	# TODO Increase checked.

	((checked++))

	echo
done < <(find . -maxdepth 1 -type f -name "*.c" -print0)

if [[ "$found_source" == false ]]; then
	echo -e "${red}No .c files found.${reset}"
fi

echo "Build summary"
echo "-------------"
echo "Files checked:		$checked"
echo "Successful builds:	$successful"
echo "Failed builds:		$failed"
