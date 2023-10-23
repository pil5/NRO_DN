function[] = calc_pi(n) %vneses stevilo tock

x=4*rand(1,n);
y=4*rand(1,n);
r=2;
c=sqrt((x-2).^2+(y-2).^2)<=r;


[notrix,notriy,zunajx,zunajy]=mcc_pi(n);
[ocenaPi,nap]=area_pi(n)
narisi_tocke(notrix,notriy,zunajx,zunajy)




function[notrix,notriy,zunajx,zunajy]=mcc_pi(n)
notrix=[];
notriy=[];
zunajx=[];
zunajy=[];
for i=1:n
    if c(i)>0
        notrix(end+1)=x(i); notriy(end+1)=y(i);
    else
        zunajx(end+1)=x(i); zunajy(end+1)=y(i);
    end
end
end


function[ocenaPi,nap]=area_pi(n)
        a=sum(c==1);
        razmerje=a/n; %je pi/4
        ocenaPi = razmerje*4;
        nap = abs(ocenaPi-pi);
end

 

    function narisi_tocke(notrix,notriy,zunajx,zunajy)
        
    plot(zunajx,zunajy,"rx");
    hold on
    
    plot(notrix,notriy,"bx");
    hold on
    
    phi=linspace(0,2*pi);
    kroznica_x = @(phi) 2+r*cos(phi);
    kroznica_y = @(phi) 2+r*sin(phi);   
    plot(kroznica_x(phi),kroznica_y(phi),"k");
     
    
    end

end
