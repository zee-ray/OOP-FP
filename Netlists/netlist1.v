module FA (A, B, Cin, S, Cout);
    input A;
    input B, Cin;
    output S, Cout;

    wire P, G, n0;

    xor (P, A, B);
    and (G, A, B);
    xor (S,P , Cin);
    and (n0, P,Cin);
    or (Cout, n0, G);
endmodule

// example, 3 input, 2 output