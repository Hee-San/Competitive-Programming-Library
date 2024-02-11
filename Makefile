test:
	python Tests/Local/verifyer/local_test.py
	oj-verify run

test-local:
	python Tests/Local/verifyer/local_test.py

test-oj:
	oj-verify all

docs:
	oj-verify docs
