-- 1. Find all customer data 
SELECT * 
FROM   banking.customer; 

-- 2. Find all branch data 
SELECT * 
FROM   banking.branch; 

-- 3. Find all accounts data 
SELECT * 
FROM   banking.account; 

-- 4. Find all depositor data 
SELECT * 
FROM   banking.depositor; 

-- 5. Find all loan data 
SELECT * 
FROM   banking.loan; 

-- 6. Find all borrower data 
SELECT * 
FROM   banking.borrower; 

-- 7. Find the names and cities of all borrower 
SELECT DISTINCT banking.customer.customer_name, 
                customer_city 
FROM   banking.borrower, 
       banking.customer 
WHERE  banking.borrower.customer_name = banking.customer.customer_name; 

-- 8. Find the names and cities of those customers, who have a loan at Perryridge bank 
SELECT DISTINCT C.customer_name, 
                customer_city 
FROM   banking.customer C, 
       banking.borrower B, 
       banking.loan L 
WHERE  C.customer_name = B.customer_name 
       AND B.loan_number = L.loan_number 
       AND branch_name LIKE 'Perryridge'; 

-- 9. Find account numbers 
SELECT account_number 
FROM   banking.account; 

-- 10. Find all accounts with balances between 700 and 900 
SELECT account_number 
FROM   banking.account 
WHERE  balance BETWEEN 700 AND 900; 

-- 11. Find the names of those customers on streets ending in "Hill" 
SELECT customer_name 
FROM   banking.customer 
WHERE  customer_street LIKE '%Hill'; 

-- 12. Find the names of all customers with both accounts and loans at Perryridge Bank 
SELECT DISTINCT customer_name 
FROM   banking.borrower, 
       banking.loan 
WHERE  banking.borrower.loan_number = banking.loan.loan_number 
       AND branch_name = 'Perryridge' 
       AND customer_name IN (SELECT customer_name 
                             FROM   banking.account, 
                                    banking.depositor 
                             WHERE  banking.account.account_number = 
                                    banking.depositor.account_number 
                                    AND branch_name = 'Perryridge'); 

-- 13. Find the names of customers with an account but not a loan at Perryridge Bank 
SELECT DISTINCT customer_name 
FROM   banking.account, 
       banking.depositor 
WHERE  banking.account.account_number = banking.depositor.account_number 
       AND branch_name = 'Perryridge' 
       AND customer_name NOT IN (SELECT customer_name 
                                 FROM   banking.loan, 
                                        banking.borrower 
                                 WHERE  banking.loan.loan_number = banking.borrower.loan_number 
                                        AND branch_name = 'Perryridge'); 

-- 14. Find the names of customers with accounts at a branch where Hayes has 
SELECT DISTINCT D.customer_name 
FROM   banking.depositor D, 
       banking.account A 
WHERE  D.account_number = A.account_number 
       AND branch_name IN (SELECT branch_name 
                           FROM   banking.depositor Dh, 
                                  banking.account Ah 
                           WHERE  Dh.account_number = Ah.account_number 
                                  AND Dh.customer_name = 'Hayes'); 

-- 15. Find the names of branches whose assets are greater than the assets from some branch in Brooklyn
SELECT branch_name 
FROM   banking.branch 
WHERE  assets > SOME (SELECT assets 
                      FROM   banking.branch 
                      WHERE  branch_city = 'Brooklyn'); 

-- 16. Find the names of branches whose assets are greater than the assets from all branch in Brooklyn
SELECT branch_name 
FROM   banking.branch 
WHERE  assets > ALL (SELECT assets 
                     FROM   banking.branch 
                     WHERE  branch_city = 'Brooklyn'); 

-- 17. Find the names of customers with both accounts and loans at Perryridge branch (using exists)
SELECT customer_name 
FROM   banking.customer 
WHERE  EXISTS (SELECT * 
               FROM   banking.account, 
                      banking.depositor 
               WHERE  banking.account.account_number = banking.depositor.account_number 
                      AND banking.depositor.customer_name = banking.customer.customer_name 
                      AND branch_name = 'Perryridge') 
       AND EXISTS (SELECT * 
                   FROM   banking.loan, 
                          banking.borrower 
                   WHERE  banking.loan.loan_number = banking.borrower.loan_number 
                          AND banking.borrower.customer_name = banking.customer.customer_name 
                          AND branch_name = 'Perryridge'); 

-- 18. Find the names of customers with an account but bot a loan at Perryridge branch (using exists)
SELECT customer_name 
FROM   banking.customer 
WHERE  EXISTS (SELECT * 
               FROM   banking.account, 
                      banking.depositor 
               WHERE  banking.account.account_number = banking.depositor.account_number 
                      AND banking.depositor.customer_name = banking.customer.customer_name 
                      AND branch_name = 'Perryridge') 
       AND NOT EXISTS (SELECT * 
                       FROM   banking.loan, 
                              banking.borrower 
                       WHERE  banking.loan.loan_number = banking.borrower.loan_number 
                              AND banking.borrower.customer_name = 
                                  banking.customer.customer_name 
                              AND branch_name = 'Perryridge'); 

-- 19. Find the names of customers at Perryridge Bank, in alphabetical order 
SELECT DISTINCT customer_name 
FROM   banking.borrower, 
       banking.loan, 
       banking.branch 
WHERE  banking.borrower.loan_number = banking.loan.loan_number 
       AND banking.loan.branch_name = 'Perryridge' 
ORDER  BY banking.borrower.customer_name; 

-- 20. Find the loan data, ordered by decreasing amounts, then increasing loan numbers 
SELECT * 
FROM   banking.loan 
ORDER  BY amount DESC, 
          loan_number ASC; 

-- 21. Find the names of branches having at least one account, with average account balance 
SELECT branch_name, 
       Avg(balance) 
FROM   banking.account 
GROUP  BY branch_name; 

-- 22. Find the branches having at least one account, with size of set of customers 
SELECT branch_name, 
       Count(DISTINCT customer_name) 
FROM   banking.depositor, 
       banking.account 
WHERE  banking.depositor.account_number = banking.account.account_number 
GROUP  BY branch_name; 

-- 23. Find the average balance for all accounts 
SELECT Avg(balance) 
FROM   banking.account; 

-- 24. Find the names of all branches having at least one account with average balances of accounts at each branch if the average is above 700.
SELECT branch_name, 
       Avg(balance) 
FROM   banking.account 
GROUP  BY branch_name 
HAVING Avg(balance) > 700; 

-- 25. Find the name of branches having the largest average balance 
SELECT branch_name 
FROM   banking.account 
GROUP  BY branch_name 
HAVING Avg(balance) >= ALL (SELECT Avg(balance) 
                            FROM   banking.account 
                            GROUP  BY branch_name); 

-- OR 
SELECT branch_name 
FROM   banking.account 
GROUP  BY branch_name 
HAVING Avg(balance) = (SELECT Max(Avg(balance)) 
                       FROM   banking.account 
                       GROUP  BY branch_name); 

-- 26. Find the number of customers 
SELECT Count (*) 
FROM   banking.customer; 

-- 27. Find the average balance of all customers in Harrison having at least 2 accounts 
SELECT Avg(balance) 
FROM   banking.depositor, 
       banking.account, 
       banking.customer 
WHERE  banking.depositor.customer_name = banking.customer.customer_name 
       AND banking.depositor.account_number = banking.account.account_number 
       AND customer_city = 'Harrison' 
GROUP  BY banking.depositor.customer_name 
HAVING Count (DISTINCT banking.account.account_number) >= 2; 

-- 28. Find the branches whose assets are greater than the average assets from all branches in Brooklyn and list them by the assets in decreasing order and by their names in alphabetical order
SELECT branch_name, 
       assets 
FROM   banking.branch 
WHERE  assets > (SELECT Avg(assets) 
                 FROM   banking.branch 
                 WHERE  branch_city = 'Brooklyn') 
ORDER  BY assets DESC, 
          branch_name ASC; 

-- 29. Find branches whose number of loans greater than the average loan number and whose number of accounts are less than the average number of accounts with name, loan number and account number
SELECT banking.loan.branch_name, 
       num_of_loans, 
       num_of_accounts 
FROM   (SELECT Count(*) AS num_of_loans, 
               branch_name 
        FROM   banking.loan 
        GROUP  BY branch_name 
        HAVING Count(*) >= (SELECT Avg(Count(*)) 
                            FROM   banking.loan 
                            GROUP  BY branch_name)) banking.loan 
       -- Number of accounts by branches 
       join (SELECT Count(*) AS num_of_accounts, 
                    branch_name 
             FROM   banking.account 
             GROUP  BY branch_name 
             HAVING Count(*) <= (SELECT Avg(Count(*)) 
                                 FROM   banking.account 
                                 GROUP  BY branch_name)) acc 
         ON banking.loan.branch_name = acc.branch_name; 

-- 30. Find the names of customers who has bank accounts exactly where Hayes has. 
SELECT customer_name 
FROM   banking.account a 
       join banking.depositor d 
         ON a.account_number = d.account_number 
WHERE  branch_name IN (SELECT branch_name 
                       FROM   banking.account a 
                              join banking.depositor d 
                                ON a.account_number = d.account_number 
                       WHERE  customer_name = 'Hayes') 
GROUP  BY customer_name 
HAVING Count(DISTINCT branch_name) = (SELECT Count(DISTINCT branch_name) 
                                      FROM   banking.account a 
                                             join banking.depositor d 
                                               ON a.account_number = 
                                                  d.account_number 
                                      WHERE  customer_name = 'Hayes'); 

--OR
SELECT DISTINCT customer_name 
FROM   banking.account 
       join banking.depositor 
         ON banking.account.account_number = banking.depositor.account_number 
WHERE  branch_name IN (SELECT DISTINCT branch_name 
                       FROM   banking.account 
                              join banking.depositor 
                                ON banking.account.account_number = 
                                   banking.depositor.account_number 
                       WHERE  customer_name LIKE 'Hayes') 
GROUP  BY customer_name 
HAVING Count(DISTINCT banking.account.branch_name) = (SELECT Count(DISTINCT branch_name) 
                                              FROM   banking.account 
                                                     join banking.depositor 
                                                       ON 
              banking.account.account_number = banking.depositor.account_number 
                                              WHERE  customer_name LIKE 'Hayes'); 

--OR 
SELECT customer_name 
FROM   banking.customer 
MINUS 
SELECT DISTINCT customer_name 
FROM   (SELECT customer_name, 
               branch_name 
        FROM   banking.customer, 
               (SELECT DISTINCT branch_name 
                FROM   banking.account, 
                       banking.depositor 
                WHERE  banking.account.account_number = banking.depositor.account_number 
                       AND customer_name LIKE 'Hayes') 
        MINUS 
        SELECT customer_name, 
               branch_name 
        FROM   banking.account, 
               banking.depositor 
        WHERE  banking.account.account_number = banking.depositor.account_number); 

