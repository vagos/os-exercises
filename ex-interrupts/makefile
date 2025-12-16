.PHONY: clean watch

PDFS=build/main.pdf

all: $(PDFS)

build/%.pdf: %.tex
	mkdir -p build
	xelatex -output-directory=build $*.tex

clean:
	rm -r build

watch:
	find . -name "*.tex" | entr make
