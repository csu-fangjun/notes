.PHONY: run clean

run: hello.jar
	java -jar ./hello.jar

hello.jar: hello.kt
	kotlinc -include-runtime -d hello.jar hello.kt

clean:
	$(RM) hello.jar
