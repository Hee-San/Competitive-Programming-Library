import os
import glob
import os

# テストケースは、以下の条件を満たすファイルである
# 1. ファイル名が「test_*.cpp」である
# 2. 同じ階層に「input/」「output/」ディレクトリが存在する
# 3. input/ディレクトリ内のファイル名とoutput/ディレクトリ内のファイル名が一致する

# テストケースのディレクトリ
current_dir = os.path.dirname(os.path.abspath(__file__))
test_dir = os.path.join(current_dir, "../")

test_file_name = "main.cpp"

# テスト候補一覧
candidate_test_files = glob.glob(f"{test_dir}/**/{test_file_name}", recursive=True)


class TestCase:
    def __init__(self, file, input_files, output_files):
        self.file = file
        self.input_files = input_files
        self.output_files = output_files

    def num_cases(self):
        return len(self.input_files)

    def name(self):
        # test_dir以下のパス(ファイル名を除く)を、_で繋いだものをテストケース名とする
        path = os.path.relpath(self.file, test_dir)
        path = path.replace(f"/{test_file_name}", "")
        return path.replace("/", "_")

test_cases = []
for file in candidate_test_files:
    dir = os.path.dirname(file)
    input_files = glob.glob(f"{dir}/input/*")
    output_files = glob.glob(f"{dir}/output/*")
    if len(input_files) == 0:
        print(f"Skip: {file} にはinput/ディレクトリが存在しません")
        continue
    if len(output_files) == 0:
        print(f"Skip: {file} にはoutput/ディレクトリが存在しません")
        continue

    # input/ディレクトリ内のファイル名とoutput/ディレクトリ内のファイル名が一致するか
    input_files = [os.path.basename(file) for file in input_files]
    output_files = [os.path.basename(file) for file in output_files]
    if input_files != output_files:
        print(f"Skip: {file} のinput/ディレクトリとoutput/ディレクトリのファイル名が一致しません")
        continue

    input_files.sort()
    output_files.sort()

    test_cases.append(TestCase(file, input_files, output_files))

test_cases.sort(key=lambda x: x.name())

# テストケース一覧を表示
print("テストケース一覧")
for test_case in test_cases:
    print(f"- {test_case.name()}: {test_case.num_cases()} cases")
print()



# テストケースの実行(c++)
import subprocess
import colorama
from colorama import Fore, Style
import difflib
import os
from difflib import HtmlDiff
# Initialize colorama
colorama.init()

ac_count = 0
wa_count = 0
re_count = 0
wa_cases = []
re_cases = []

# Remove existing HTML files
html_files = glob.glob(f"{test_dir}/tmp/**/*.html", recursive=True)
for file in html_files:
    os.remove(file)

for test_case in test_cases:
    print(f"{Fore.BLUE}テストケース: {test_case.name()}{Style.RESET_ALL}")
    for i in range(test_case.num_cases()):
        input_file = f"{test_case.file.replace(test_file_name, 'input')}/{test_case.input_files[i]}"
        output_file = f"{test_case.file.replace(test_file_name, 'output')}/{test_case.output_files[i]}"
        print(f"{Fore.YELLOW}Case: {test_case.input_files[i]}{Style.RESET_ALL}")

        # Run oj-bundle command to expand includes
        try:
            bundled_code = subprocess.run(["oj-bundle", test_case.file], check=True, capture_output=True, text=True).stdout
            bundled_file = os.path.join(os.path.dirname(test_case.file), "bundled.cpp")
            with open(bundled_file, "w") as f:
                f.write(bundled_code)
        except subprocess.CalledProcessError as e:
            print(f"{Fore.RED}Failed to run oj-bundle command: {e}{Style.RESET_ALL}")
            continue

        # Execute the bundled C++ code
        try:
            result = subprocess.run(["g++", bundled_file, "-std=c++17", "-o", "/tmp/a.out"], check=True, capture_output=True)
            result = subprocess.run(["/tmp/a.out"], input=open(input_file, "r").read(), check=True, capture_output=True, text=True)
            expected_output = open(output_file, "r").read()
            if result.stdout == expected_output:
                print(f"{Fore.GREEN}Result: AC{Style.RESET_ALL}")
                ac_count += 1
            else:
                print(f"{Fore.RED}Result: WA{Style.RESET_ALL}")
                wa_count += 1
                wa_cases.append(test_case.name())
                diff = difflib.unified_diff(expected_output.splitlines(), result.stdout.splitlines(), lineterm="")
                diff_str = "\n".join(diff)
                print(diff_str)

                # Save diff in HTML format
                html_diff = HtmlDiff()
                html_file = f"{test_dir}/tmp/{test_case.output_files[i]}.html"
                with open(html_file, "w") as f:
                    f.write(html_diff.make_file(expected_output.splitlines(), result.stdout.splitlines()))
                print(f"Diff: {html_file}")
        except subprocess.CalledProcessError as e:
            print(f"{Fore.RED}Result: WA (exit code: {e.returncode}){Style.RESET_ALL}")
            print(e.stderr)
            wa_count += 1
            wa_cases.append(test_case.name())
        except Exception as e:
            print(f"{Fore.RED}Result: RE{Style.RESET_ALL}")
            print(e)
            re_count += 1
            re_cases.append(test_case.name())
        print()
    print()

# Print colored counts
ac_count_str = f"{Fore.GREEN}{ac_count}{Style.RESET_ALL}"
wa_count_str = f"{Fore.RED}{wa_count}{Style.RESET_ALL}"
re_count_str = f"{Fore.RED}{re_count}{Style.RESET_ALL}"

if ac_count > 0:
    print(f"AC: {ac_count_str} cases")
if wa_count > 0:
    print(f"WA: {wa_count_str} cases ({', '.join(wa_cases)})")
if re_count > 0:
    print(f"RE: {re_count_str} cases ({', '.join(re_cases)})")
