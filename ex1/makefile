.PHONY: clean watch

PDFS=build/main.pdf

all: $(PDFS)

build/%.pdf: %.tex
	xelatex -output-directory=build $*.tex

clean:
	rm *.pdf

watch:
	find . -name "*.tex" | entr make
