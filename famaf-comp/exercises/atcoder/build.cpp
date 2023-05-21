vector<ll> recon;
build(x,w) {
	ll res=f(x,w);
	if(res==f(x+1,w))	// conviene preguntar siempre primero esta
		build(x+1,w)
	else
		recon.pb(x);
		build(x+1,w-p[x]);
}
// reconstruir el camino a la respuesta
