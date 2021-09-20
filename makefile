all:
	gcc secantes.c -o secantes_exec -lm
	gcc newton.c -o newton_exec -lm
	gcc bissecao.c -o bissecao_exec -lm
run:
	./bissecao_exec
	./newton_exec
	./secantes_exec
	rm bissecao_exec
	rm newton_exec
	rm secantes_exec