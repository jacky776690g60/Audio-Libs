<h1 style="color: white; background: linear-gradient(43deg, #4158D0 0%, #d253c3 58%, #FB5959 100%); text-align: center; padding: 10px; box-shadow: 3px 3px 10px rgba(0,0,0,0.2); font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; border-radius: 5px; text-transform: capitalize;">
  Utility
</h1>

> <h2 id='0'>Table of Content</h2>

1. <a href='#dbconverter'>DBconverter.h</a>
2. <a href='#Colors'>Colors.h</a>


<h1 id="Colors" style="font-weight: 600; text-transform: capitalize; font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; color: #EA638C;">Colors.h</h1>
<a href='#0' style='background: #000; margin:0 auto; padding: 5px; border-radius: 5px;'>Back to ToC</a><br><br>

- `Colors`: Contains predefined colors which can also be found on <a href='https://jacktogon.com/'>jacktogon.com</a>

---

<h1 id="conversion" style="padding: 2px 5px; border-radius: 5px; font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; color: #EA638C;">DBconverter.h</h1>
<a href='#0' style='background: #000; padding: 5px; border-radius: 5px;'>Back to ToC</a>
<br><br>

* `Linear to Decibels`: converting linear number to decibels
  
$$
\text{dB} = 
\begin{cases} 
20 \cdot \log_{10}(\text{linearGain}) & \text{if } \text{linearGain} > 0 \\
-\infty & \text{otherwise}
\end{cases}
$$

* `Decibels to Linear`: converting decibels to linear number
  
$$
\text{linearGain} = 10^{\frac{\text{dB}}{20}}
$$

---