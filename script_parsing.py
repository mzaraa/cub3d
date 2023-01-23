import argparse
import subprocess
import os
from termcolor import colored

def test_cub3D(maps_dir, valgrind=False):
    print(colored("Tests starting...", "yellow"))
    files = os.listdir(maps_dir)

    success_count = 0
    failure_count = 0

    for file in files:
        print()
        try:
            if valgrind:
                result = subprocess.run(["valgrind", "--leak-check=full", "./cub3D", os.path.join(maps_dir, file)],
                                        stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE,
                                        timeout=10)
                print(result.stderr.decode())
                if "ERROR SUMMARY: 0 errors from 0 contexts" in result.stderr.decode():
                    print(colored("Test for file :", "blue") + f" {file} -> " + colored("Passed without leaks!", "green"))
                    success_count += 1
                else:
                    print(colored(f"Test for file : {file} -> Leaks detected!", "red"))
                    failure_count += 1
            else:
                result = subprocess.run(["./cub3D", os.path.join(maps_dir, file)],
                                        stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE,
                                        timeout=10)
                print(result.stdout.decode())
                if b"Error\n" in result.stdout:
                    print(colored(f"Test for file : {file} -> Passed!", "green"))
                    success_count += 1
                else:
                    print(colored(f"Test for file : {file} -> Failed!", "red"))
                    failure_count += 1
        except subprocess.TimeoutExpired:
            print(colored(f"Test for file : {file} -> Timed out!", "red"))
            failure_count += 1
    print()
    print(colored(f"{success_count} tests successful, {failure_count} tests failed.", "yellow"))

# setup argument parser
parser = argparse.ArgumentParser(description='Test cub3D program')
parser.add_argument('-valgrind', action='store_true', help='Run test with valgrind')
args = parser.parse_args()

try:
    test_cub3D("maps_invalid", valgrind=args.valgrind)
except KeyboardInterrupt:
    print(colored("Test interrupted by user", "yellow"))