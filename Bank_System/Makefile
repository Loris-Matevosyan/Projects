.PHONY: buildcmake exec delete createdir createcmake

buildcmake:
	@cd build && cmake --build .

exec:
	@build/application/BankSystem.exe

delete:
	@rmdir /S /Q build

createdir:
	@mkdir build

createcmake:
	@cd build && cmake ..