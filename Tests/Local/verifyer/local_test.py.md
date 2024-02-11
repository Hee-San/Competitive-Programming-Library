---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import os\nimport glob\nimport os\n\n# \u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\
    \u306F\u3001\u4EE5\u4E0B\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u30D5\u30A1\
    \u30A4\u30EB\u3067\u3042\u308B\n# 1. \u30D5\u30A1\u30A4\u30EB\u540D\u304C\u300C\
    test_*.cpp\u300D\u3067\u3042\u308B\n# 2. \u540C\u3058\u968E\u5C64\u306B\u300C\
    input/\u300D\u300Coutput/\u300D\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u304C\u5B58\
    \u5728\u3059\u308B\n# 3. input/\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u5185\u306E\
    \u30D5\u30A1\u30A4\u30EB\u540D\u3068output/\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\
    \u5185\u306E\u30D5\u30A1\u30A4\u30EB\u540D\u304C\u4E00\u81F4\u3059\u308B\n\n#\
    \ \u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u306E\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\
    \ncurrent_dir = os.path.dirname(os.path.abspath(__file__))\ntest_dir = os.path.join(current_dir,\
    \ \"../\")\n\ntest_file_name = \"main.cpp\"\n\n# \u30C6\u30B9\u30C8\u5019\u88DC\
    \u4E00\u89A7\ncandidate_test_files = glob.glob(f\"{test_dir}/**/{test_file_name}\"\
    , recursive=True)\n\n\nclass TestCase:\n    def __init__(self, file, input_files,\
    \ output_files):\n        self.file = file\n        self.input_files = input_files\n\
    \        self.output_files = output_files\n\n    def num_cases(self):\n      \
    \  return len(self.input_files)\n\n    def name(self):\n        # test_dir\u4EE5\
    \u4E0B\u306E\u30D1\u30B9(\u30D5\u30A1\u30A4\u30EB\u540D\u3092\u9664\u304F)\u3092\
    \u3001_\u3067\u7E4B\u3044\u3060\u3082\u306E\u3092\u30C6\u30B9\u30C8\u30B1\u30FC\
    \u30B9\u540D\u3068\u3059\u308B\n        path = os.path.relpath(self.file, test_dir)\n\
    \        path = path.replace(f\"/{test_file_name}\", \"\")\n        return path.replace(\"\
    /\", \"_\")\n\ntest_cases = []\nfor file in candidate_test_files:\n    dir = os.path.dirname(file)\n\
    \    input_files = glob.glob(f\"{dir}/input/*\")\n    output_files = glob.glob(f\"\
    {dir}/output/*\")\n    if len(input_files) == 0:\n        print(f\"Skip: {file}\
    \ \u306B\u306Finput/\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u304C\u5B58\u5728\u3057\
    \u307E\u305B\u3093\")\n        continue\n    if len(output_files) == 0:\n    \
    \    print(f\"Skip: {file} \u306B\u306Foutput/\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\
    \u304C\u5B58\u5728\u3057\u307E\u305B\u3093\")\n        continue\n\n    # input/\u30C7\
    \u30A3\u30EC\u30AF\u30C8\u30EA\u5185\u306E\u30D5\u30A1\u30A4\u30EB\u540D\u3068\
    output/\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u5185\u306E\u30D5\u30A1\u30A4\u30EB\
    \u540D\u304C\u4E00\u81F4\u3059\u308B\u304B\n    input_files = [os.path.basename(file)\
    \ for file in input_files]\n    output_files = [os.path.basename(file) for file\
    \ in output_files]\n    if input_files != output_files:\n        print(f\"Skip:\
    \ {file} \u306Einput/\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u3068output/\u30C7\u30A3\
    \u30EC\u30AF\u30C8\u30EA\u306E\u30D5\u30A1\u30A4\u30EB\u540D\u304C\u4E00\u81F4\
    \u3057\u307E\u305B\u3093\")\n        continue\n\n    input_files.sort()\n    output_files.sort()\n\
    \n    test_cases.append(TestCase(file, input_files, output_files))\n\ntest_cases.sort(key=lambda\
    \ x: x.name())\n\n# \u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u4E00\u89A7\u3092\u8868\
    \u793A\nprint(\"\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u4E00\u89A7\")\nfor test_case\
    \ in test_cases:\n    print(f\"- {test_case.name()}: {test_case.num_cases()} cases\"\
    )\nprint()\n\n\n\n# \u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u306E\u5B9F\u884C(c++)\n\
    import subprocess\nimport colorama\nfrom colorama import Fore, Style\nimport difflib\n\
    import os\nfrom difflib import HtmlDiff\n# Initialize colorama\ncolorama.init()\n\
    \nac_count = 0\nwa_count = 0\nre_count = 0\nwa_cases = []\nre_cases = []\n\n#\
    \ Remove existing HTML files\nhtml_files = glob.glob(f\"{test_dir}/tmp/**/*.html\"\
    , recursive=True)\nfor file in html_files:\n    os.remove(file)\n\nfor test_case\
    \ in test_cases:\n    print(f\"{Fore.BLUE}\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\
    : {test_case.name()}{Style.RESET_ALL}\")\n    for i in range(test_case.num_cases()):\n\
    \        input_file = f\"{test_case.file.replace(test_file_name, 'input')}/{test_case.input_files[i]}\"\
    \n        output_file = f\"{test_case.file.replace(test_file_name, 'output')}/{test_case.output_files[i]}\"\
    \n        print(f\"{Fore.YELLOW}Case: {test_case.input_files[i]}{Style.RESET_ALL}\"\
    )\n\n        # Run oj-bundle command to expand includes\n        try:\n      \
    \      bundled_code = subprocess.run([\"oj-bundle\", test_case.file], check=True,\
    \ capture_output=True, text=True).stdout\n            bundled_file = os.path.join(os.path.dirname(test_case.file),\
    \ \"bundled.cpp\")\n            with open(bundled_file, \"w\") as f:\n       \
    \         f.write(bundled_code)\n        except subprocess.CalledProcessError\
    \ as e:\n            print(f\"{Fore.RED}Failed to run oj-bundle command: {e}{Style.RESET_ALL}\"\
    )\n            continue\n\n        # Execute the bundled C++ code\n        try:\n\
    \            result = subprocess.run([\"g++\", bundled_file, \"-std=c++17\", \"\
    -o\", \"/tmp/a.out\"], check=True, capture_output=True)\n            result =\
    \ subprocess.run([\"/tmp/a.out\"], input=open(input_file, \"r\").read(), check=True,\
    \ capture_output=True, text=True)\n            expected_output = open(output_file,\
    \ \"r\").read()\n            if result.stdout == expected_output:\n          \
    \      print(f\"{Fore.GREEN}Result: AC{Style.RESET_ALL}\")\n                ac_count\
    \ += 1\n            else:\n                print(f\"{Fore.RED}Result: WA{Style.RESET_ALL}\"\
    )\n                wa_count += 1\n                wa_cases.append(test_case.name())\n\
    \                diff = difflib.unified_diff(expected_output.splitlines(), result.stdout.splitlines(),\
    \ lineterm=\"\")\n                diff_str = \"\\n\".join(diff)\n            \
    \    print(diff_str)\n\n                # Save diff in HTML format\n         \
    \       html_diff = HtmlDiff()\n                html_file = f\"{test_dir}/tmp/{test_case.output_files[i]}.html\"\
    \n                with open(html_file, \"w\") as f:\n                    f.write(html_diff.make_file(expected_output.splitlines(),\
    \ result.stdout.splitlines()))\n                print(f\"Diff: {html_file}\")\n\
    \        except subprocess.CalledProcessError as e:\n            print(f\"{Fore.RED}Result:\
    \ WA (exit code: {e.returncode}){Style.RESET_ALL}\")\n            errLines = []\n\
    \            if isinstance(e.stderr, str):\n                errLines = e.stderr.split(\"\
    \\n\")\n            else:\n                errLines = e.stderr.decode().split(\"\
    \\n\")\n\n            for line in errLines:\n                print(f\"  {line}\"\
    )\n            wa_count += 1\n            wa_cases.append(test_case.name())\n\
    \        except Exception as e:\n            print(f\"{Fore.RED}Result: RE{Style.RESET_ALL}\"\
    )\n            print(e)\n            re_count += 1\n            re_cases.append(test_case.name())\n\
    \        print()\n    print()\n\n# Print colored counts\nac_count_str = f\"{Fore.GREEN}{ac_count}{Style.RESET_ALL}\"\
    \nwa_count_str = f\"{Fore.RED}{wa_count}{Style.RESET_ALL}\"\nre_count_str = f\"\
    {Fore.RED}{re_count}{Style.RESET_ALL}\"\n\nif ac_count > 0:\n    print(f\"AC:\
    \ {ac_count_str} cases\")\nif wa_count > 0:\n    print(f\"WA: {wa_count_str} cases\
    \ ({', '.join(wa_cases)})\")\nif re_count > 0:\n    print(f\"RE: {re_count_str}\
    \ cases ({', '.join(re_cases)})\")\n"
  dependsOn: []
  isVerificationFile: false
  path: Tests/Local/verifyer/local_test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Tests/Local/verifyer/local_test.py
layout: document
redirect_from:
- /library/Tests/Local/verifyer/local_test.py
- /library/Tests/Local/verifyer/local_test.py.html
title: Tests/Local/verifyer/local_test.py
---
