run: limpiar util articulo producto carrito cliente proveedor main

main:
	gcc utils.o client.o provider.o article.o product.o cart.o main.c -o main

carrito:
	gcc ../cart/cart.c -c

producto:
	gcc ../product/product.c -c

articulo:
	gcc ../article/article.c -c

proveedor:
	gcc ../provider/provider.c -c

cliente:
	gcc ../client/client.c -c

util:
	gcc ../utils/utils.c -c

limpiar:
	rm -rf main
	rm -rf *.o