package com.algorithm;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class 删除连续字符 {
    /*
     * 删除连续字符，大小写不敏感
     * 例子：ABBCCCCCCBBAB =》 ABCBAB
     * aAC =》 aC
     * */

    public static String remove(String str) {
        if (str.length() < 1)
            return str;
        String res = str.substring(0, 1);
        for (int i = 1; i < str.length(); i++) {
            String pre = str.substring(i - 1, i).toLowerCase();
            String cur = str.substring(i, i + 1).toLowerCase();
            if (!pre.equals(cur))
                res += str.substring(i, i + 1);
        }
        return res;
    }

    //正则表达式
    public static String remove_2(String str) {
        String regex = "(.)\\1+";
        Matcher matcher = Pattern.compile(regex).matcher(str);
        String res = matcher.replaceAll("$1");
        return res;
    }

    //第二种正则的表示法
    public static String remove_3(String str) {
        String res = "";
        Matcher m = Pattern.compile("(\\w)\\1*").matcher(str);// Pattern pattern = Pattern.compile("(.)\\1*");
        while (m.find()) {
            res += m.group().subSequence(0, 1);
        }
        return res;
    }

    public static void main(String[] args) {
        String str = "ABBCCCCCCBBAB";
        System.out.println(remove(str));
        System.out.println(remove_2(str));
        System.out.println(remove_3(str));
    }
}
