#!/usr/bin/env bash

# variables 
cub3D=./cub3D
maps_folder=./maps_invalid/
leaks_folder=leaks
valgrind=false
output_folder=outputs
exit_code=0
number_of_tests=0

# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

# Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

# High Intensity
IBlack='\033[0;90m'       # Black
IRed='\033[0;91m'         # Red
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
IBlue='\033[0;94m'        # Blue
IPurple='\033[0;95m'      # Purple
ICyan='\033[0;96m'        # Cyan
IWhite='\033[0;97m'       # White

# Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue
BIPurple='\033[1;95m'     # Purple
BICyan='\033[1;96m'       # Cyan
BIWhite='\033[1;97m'      # White

# High Intensity backgrounds
On_IBlack='\033[0;100m'   # Black
On_IRed='\033[0;101m'     # Red
On_IGreen='\033[0;102m'   # Green
On_IYellow='\033[0;103m'  # Yellow
On_IBlue='\033[0;104m'    # Blue
On_IPurple='\033[0;105m'  # Purple
On_ICyan='\033[0;106m'    # Cyan
On_IWhite='\033[0;107m'   # White


#	$#		=>	number of arguments
#	-gt 1	=>	greater than 1
if [ $# -gt 1 ]; then
	echo "Not valid arguments"
	exit 1
#	-eq 1	=>	equal to 1
elif [[ $# -eq 1 ]]; then
	if [[ $1 == "-h" ]]; then
		echo "${BBlue}This script have 2 option flag available${Color_Off} => ${BRed}-h${Color_Off} and ${BRed}-l${Color_Off}"
		echo ""
		echo "'-h' for help, display this informations about how to use this script."

		echo "'-l' to check leaks, this will create a folder named 'leaks' and store the leaks in it."
		echo ""
		echo "${BBlue}Usage :${Color_Off}"
		echo "	sh tester_parsing.sh -h"
		echo "	sh tester_parsing.sh -l"
		exit 1
	fi
	if [ $1 == "-l" ]; then
		valgrind=true
	else
		echo "Not valid arguments"
		exit 1
	fi
fi

# header of the script
echo "==========================================================="
echo -e "${BYellow}                   Cub3D parsing tester                     ${Color_Off}"
echo "==========================================================="

# check if the program exist
if [ ! -f $cub3D ]; then
	echo -e "${BRed}Error :${Color_Off} $cub3D ${BRed}not found${Color_Off}"
	exit 1
fi

# check if the maps folder exist
if [ ! -d $maps_folder ]; then
	echo -e "${BRed}Error :${Color_Off} $maps_folder ${BRed}not found${Color_Off}"
	exit 1
fi

# if valgrind flag is set to true then create a folder to store the leaks
if [ $valgrind == true ]; then
	if [[ ! -d $leaks_folder ]]; then
		mkdir $leaks_folder
	fi
fi

# if valgrind flag is set to false then print that leaks will not be checked and that the user can use the -l flag
if [ $valgrind == false ]; then
	echo -e "${BRed}Warning :${Color_Off} ${BRed}Leaks will not be checked${Color_Off}"
	echo -e "${BRed}Warning :${Color_Off} ${BRed}You can use the -l flag to check leaks${Color_Off}"
	read -p "Press enter to continue"
fi

# if not folder to store output then create it
if [ ! -d $output_folder ]; then
	mkdir $output_folder
fi

# loop on all the maps in the folder
for map in $maps_folder*.cub; do
	# check if the map exist
	if [ ! -f $map ]; then
		echo -e "${BRed}Error :${Color_Off} $map ${BRed}not found${Color_Off}"
		exit 1
	fi
	number_of_tests=$((number_of_tests + 1))

	# get the name of the map test for creating the log file
	map_name=$(echo $map | cut -d'/' -f 3 | cut -d'.' -f 1)
	echo ""
	# display title to know which map is tested
	echo -en "${BBlue}Test $number_of_tests${Color_Off} ${Yellow} $map_name ${Color_Off}: "
	if [ $valgrind == true ]; then
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$leaks_folder/$map_name.log $cub3D $map > $output_folder/$map_name.txt
		if [ $? -eq 139 ]; then
			echo -en "	${BRed}KO${Color_Off} $cub3D ${BRed} => segmentation fault${Color_Off} on $map_name"
			continue
		fi
		if [ $? -eq 134 ]; then
			echo -en "	${BRed}KO${Color_Off} $cub3D ${BRed} => bus error${Color_Off} on $map_name"
			continue
		fi
		lost=$(cat $leaks_folder/$map_name.log | grep "definitely lost:" | cut -d':' -f 2 | cut -d' ' -f 2)
		indirect=$(cat $leaks_folder/$map_name.log | grep "indirectly lost:" | cut -d':' -f 2 | cut -d' ' -f 2)
		if [ ${lost} == ${indirect}]; then
			echo -en "${BGreen}OK${Color_Off}"
		else
			echo -en "${BRed}KO${Color_Off} $cub3D ${BRed} => leaks${Color_Off} on $map_name"
			continue
		fi
	else
		echo -n ' ' > $output_folder/$map_name.txt
		# run the program with the map and check if the exit code is 139 (segmentation fault)
		$cub3D $map > $output_folder/$map_name.txt
		if [ $? -eq 139 ]; then
			echo -en "	${BRed}KO${Color_Off} $cub3D ${BRed} => segmentation fault${Color_Off} on $map_name"
			continue
		fi
		if [ $? -eq 134 ]; then
			echo -en "	${BRed}KO${Color_Off} $cub3D ${BRed} => bus error${Color_Off} on $map_name"
			continue
		fi
		# check if the program return an error message, if yes the test passed
		cat $output_folder/$map_name.txt | grep 'Error' > /dev/null
		if [ $? -eq 0 ]; then 
			echo -en "${BGreen}OK${Color_Off}"
		else
			echo -en "${On_Red}Test failed on $map_name => ${BRed}KO${Color_Off}"
		fi
	fi
done