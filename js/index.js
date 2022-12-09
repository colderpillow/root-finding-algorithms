// root finding algorithm implementation
var TLV = 0.000001;
var h = TLV;
var expression;

function f(x) {
    let scope = {x:x};
    return (math.evaluate(expression, scope))    
}

function g(x) {
    return ((1+Math.cos(x))/3);
}

function df(x) {
    return (f(x+h) - f(x-h)) / (2*h);
}

function bisection(x,y) {
    let z;
    while((y - x) / 2 > TLV){
        z = (x + y) / 2;
        if(f(z) * f(x) >= 0){
            x = z;
        }
        else{
            y = z;
        }
    }
    return(z);
}

function newton(x) {
    let y;
    while (true){
        y = x - (f(x) / df(x));
        if (Math.abs(x - y) < TLV){
            break;
        }
        
        x = y;
    }
    return(y);  
}

function secant(x,y) {
    let z;
    while(true){
        z = x - f(x) * ((x - y) / (f(x)-f(y)));
        if (Math.abs(z - y) < TLV){
            break;
        }
        y = z;
    }
    return(z);
}

function fixed_point(x) {
    while (Math.abs(f(x)) > TLV){
        x = g(x);
    }
    return(x);
}

function false_position(x,y) {
    let z = x;
    while (Math.abs(f(x)) > TLV){
        z = x - f(x)*(y-x)/(f(y)-f(x));

        if(f(z) * f(x) < 0){
            y = z;
        }
        else{
            x = z;
        }
    }
    return(z);
}



// event handlers
document.addEventListener('DOMContentLoaded', function(){
    let submit = document.getElementById('calculate');
    submit.addEventListener('click', function(){
        expression = document.getElementById("expression").value
        var algorithm = parseInt(document.getElementById("algorithms").value);
        let x = parseFloat(document.getElementById("x").value);
        let y = parseFloat(document.getElementById("y").value);
        switch (algorithm) {
            case 1:
                document.getElementById('root').innerHTML = "Root : " + bisection(x,y).toFixed(5);
                break;
            case 2:
                document.getElementById('root').innerHTML = "Root : " + secant(x,y);
                break;
            case 3:
                document.getElementById('root').innerHTML = "Root : " + newton(x);
                break;
            case 4:
                document.getElementById('root').innerHTML = "Root : " + fixed_point(x);
                break;
            case 5:
                document.getElementById('root').innerHTML = "Root : " + false_position(x,y);
                break;
            default:
                break;
        }    
    })
})


