test:
	python Tests/Local/verifyer/local_test.py
	oj-verify run

test-local:
	python Tests/Local/verifyer/local_test.py

test-oj:
	oj-verify run

docs:
	oj-verify docs
