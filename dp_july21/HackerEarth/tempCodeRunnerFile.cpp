vi suff(1000005,0);
    for(int i=1000004; i>=0; i--){
        suff[i] = suff[i+1] + freq[i];
    }
    int q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        cout<<suff[x]<<endl;
    }