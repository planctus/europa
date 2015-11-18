/**
 * Sbkm (social bookmarking and networking)
 * OLD documentation ?
 * http://webtools.ec.europa.eu/socialbookmark/examples/index.php?page=list-parameters.html
 */
(function(win, doc) { // SHARE 0.9

    $wt.sbkm = {

        // --------------------------------------------
        // Full URL of the GET/SET counter
        // --------------------------------------------

        _services: "___sbkm_services___",
        _counter: "___sbkm_services___/count.php",
        _sharer: "___sbkm_services___/share.php",

        // --------------------------------------------
        // RUNNING PROCESS
        // --------------------------------------------

        run: function(obj) {

            $wt.sbkm.current = obj;

            // --------------------------------------------
            // USER PARAMS (SOURCE)
            // --------------------------------------------

            var p = obj.params;

            // --------------------------------------------
            // DEFAULT PARAMS
            // --------------------------------------------

            var d = {
                // sharing info
                link: "",
                title: "",
                // custom button
                text: "",
                btn: "",
                // custom presentation
                popup: true,
                to: "",
                icon: false,
                // force language
                lang: doc.lang,
                // callback option
                callback: "",
                // counter or not
                counter: (p.counter) ? {
                    url: "",
                    id: "sbkm_",
                    lang: doc.lang,
                    atleast: "",
                    similar: "",
                    tag: "",
                    params: "",
                    limit: ""
                } : false,
                // stats info
                stats: (p.stats === false) ? false : {
                    action: "log", // do-not-log
                    plugin: "bookmarks",
                    name: "",
                    link: "",
                    title: "",
                    link_bookmark: "",
                    tag: "",
                    seed: "",
                    shorten_url: false,
                    shorten_title_limit: 90
                },
                via: "" // extra param for twitter link

            };

            // ---------------------------------------
            // COUNTER OR NOT: if case "true" only used default value as {}
            // ---------------------------------------

            if (p.counter === true) {
                p.counter = d.counter;
            };

            // ---------------------------------------
            // THERE IS A "more" inside the "list"?
            // ---------------------------------------

            d.moreInList = function() {
                if (p.to) {
                    return ((p.to).indexOf("more") !== -1);
                }
                return false;
            }();

            // --------------------------------------------
            // PARAMS (FINAL)
            // --------------------------------------------

            var f = $wt.mergeParams(d, p);

            $wt.sbkm.current.params = obj.params = f;

            // ---------------------------------------
            // BUTTON OR LIST?
            // ---------------------------------------
            // LIST
            // ---------------------------------------

            if (f.popup === false) {

                obj.className = $wt.sbkm.getCSS(obj, "list");
                obj.innerHTML = $wt.sbkm.getContent(1);

                if (f.moreInList) {
                    var li = doc.createElement("li");
                    li.appendChild($wt.sbkm.getButton(true));
                    obj.getElementsByTagName("ul")[0].appendChild(li);
                }

            }

            // ---------------------------------------
            // CREATE BUTTON
            // ---------------------------------------

            else {

                var ob = $wt.sbkm.getButton();
                $wt.after(ob, obj);
                $wt.remove(obj);

            }

            // --------------------------------------------
            // CALLBACK
            // --------------------------------------------

            if (typeof window[f.callback] === "function") {
                var ref = (f.popup === false) ? obj : btn;
                window[f.callback](ref);
            }

            // --------------------------------------------
            // NEXT COMPONENT
            // --------------------------------------------

            $wt._queue("next"); // ASYNC ON

        },

        // --------------------------------------------
        // Return the content as list + pagination nav
        // --------------------------------------------

        getContent: function(page, exclude) {

            var params	= $wt.sbkm.current.params,
                isCustom = params.to,
                isList = (params.popup === false),
                haveMore = params.moreInList,
                nbrByPage = 4,
                nbrLinks = function() {
                    if (haveMore) {
                        var u = 0;
                        for (var name in $wt.sbkm.links) {
                            u++;
                        }
                        return (u - (isCustom.length-1));
                    }
                    if (isCustom) {
                        var c = isCustom.length;
                        var h = ( haveMore ) ? 1 : 0;
                        if (c) {
                            return c-h;
                        }
                    }
                    var u = 0;
                    for (var name in $wt.sbkm.links) {
                        u++;
                    }
                    return u;
                }(),
                nbrPage = Math.ceil(nbrLinks / nbrByPage),
                p = 0,
                ps = (page - 1) * nbrByPage,
                pe = ps + nbrByPage;

            if (!haveMore && isList && !exclude) { // show all as list
                ps = 0;
                pe = nbrLinks;
            }

            var sl = "";

            // DISCLAIMER

            if(!isList){
                sl += '<p><a href="javascript:$wt.sbkm.toggleDisclaimer()">'+$wt.label("sbkm", "notice", params.lang)+'</a></p>';
            }

            sl += "<ul class='wtShareNetworks'>";

            if (haveMore && isCustom && exclude) { // ALL LIST EXCEPT CUSTOM
                for (var name in $wt.sbkm.links) {
                    if (p >= ps) {
                        if ((params.to).indexOf((name.toLowerCase())) === -1) {
                            sl += $wt.sbkm.getLinks(name, $wt.sbkm.links[name]);
                        }
                        else {
                            p--;
                        }
                    }
                    p++;
                    if (p === pe) {
                        break;
                    }
                }

            }
            else if (!haveMore && isCustom) { // CUSTOM LIST EXCEPT MORE
                for (var i = ps, l = pe; i < l; i++) {
                    if (isCustom[i]) {
                        for (var name in $wt.sbkm.links) {
                            if (name.toLowerCase() === isCustom[i].toLowerCase()) {
                                sl += $wt.sbkm.getLinks(name, $wt.sbkm.links[name]);
                            }
                        }
                    }
                }
            }
            else if (isList && haveMore && isCustom) { // CUSTOM LIST WITH MORE
                for (var name in $wt.sbkm.links) {
                    if (p >= ps) {
                        if ((params.to).indexOf((name.toLowerCase())) !== -1) {
                            sl += $wt.sbkm.getLinks(name, $wt.sbkm.links[name]);
                        }
                        else {
                            p--;
                        }
                    }
                    p++;
                }
            }
            else { // LIST ALL
                for (var name in $wt.sbkm.links) {
                    if (p >= ps) {
                        sl += $wt.sbkm.getLinks(name, $wt.sbkm.links[name]);
                    }
                    p++;
                    if (p === pe) {
                        break;
                    }
                }
            }

            sl += "</ul>";


            // PAGINATION

            if ((nbrPage > 1 && !isList) || (isList && exclude)) {

                if ($wt.sbkm.currentPage === undefined) {
                    $wt.sbkm.currentPage = 1;
                }

                var dp = ($wt.sbkm.currentPage === 1) ? 'wtDisabledLink' : "";
                var dn = ($wt.sbkm.currentPage === nbrPage) ? 'wtDisabledLink' : "";

                sl += '<div class="wtShareNav"><a class="' + dp + '" href="javascript:$wt.sbkm.prevPageUpdate(' + $wt.sbkm.currentPage + ')" title="Go to previous page"><span class="wtArrow wtArrowLeft"></span>';
                sl += $wt.label("sbkm", "previous", params.lang) + '</a>';
                sl += '<a class="' + dn + '" href="javascript:$wt.sbkm.nextPageUpdate(' + $wt.sbkm.currentPage + ', ' + nbrPage + ')" title="Go to next page">';
                sl += $wt.label("sbkm", "next", params.lang) + '<span class="wtArrow wtArrowRight"></span></a></div>';

            }

            return sl;

        },

        // --------------------------------------------
        // Update the popup content (call from pagination nav)
        // --------------------------------------------

        prevPageUpdate: function(currentPage) {

            var prevPage = (currentPage > 1) ? (currentPage - 1 ) : 1;
            $wt.sbkm.currentPage = prevPage;
            $wt.sbkm.popup.content.innerHTML = $wt.sbkm.getContent( (prevPage === 1) ? 1 : prevPage, true );

        },

        nextPageUpdate: function(currentPage, nbrPage) {

            var nextPage = (currentPage < nbrPage) ? (currentPage + 1) : nbrPage;
            $wt.sbkm.currentPage = nextPage;
            $wt.sbkm.popup.content.innerHTML = $wt.sbkm.getContent( ( nextPage === nbrPage ) ? nbrPage : nextPage, true );

        },

        // --------------------------------------------
        // Return the button share with/without counter
        // --------------------------------------------
        // m = mean (true) -> use more label
        // --------------------------------------------

        getButton: function(m) {

            var p = $wt.sbkm.current.params,
                t = (p.text) ? p.text : ((m) ? $wt.label("sbkm", "more", p.lang) : $wt.label("sbkm", "share", p.lang));

            // --------------------------------------------
            // CREATE BUTTON
            // --------------------------------------------

            var btn = doc.createElement("a");
            btn.href = "javascript:void(0)";
            btn.innerHTML = t;
            btn.params = p;
            btn.id = "sbkm_" + ("" + Math.random()).split(".")[1];

            if (!m) {
                btn.className = $wt.sbkm.getCSS($wt.sbkm.current, "button");
            }
            else {
                btn.className = "wtShareMore";
            }

            // --------------------------------------------
            // BIND EVENTS
            // --------------------------------------------

            function _popShare() {
                $wt.sbkm.current = this;
                $wt.sbkm.currentPage = 1;

                var footer = $wt.label("sbkm", "note", p.lang) + ' <a href="javascript:$wt.sbkm.toggleDisclaimer()">'+$wt.label("sbkm", "close", p.lang)+'</a>';

                $wt.sbkm.popup = $wt.pop({
                    "title": $wt.label("sbkm", "share"),
                    "class": $wt.sbkm.getCSS($wt.sbkm.current, "popup"),
                    "header": $wt.sbkm.buildHeader($wt.label("sbkm", "share", p.lang)),
                    "content": $wt.sbkm.getContent(1, m),
                    "footer": footer
                });
            };

            /*if ( $wt.browser.touch ) {
             btn.ontouchstart = _popShare;
             }
             else {*/
            btn.onclick = _popShare;
            //}

            // --------------------------------------------
            // GET AND CREATE COUNTER
            // --------------------------------------------

            if (typeof p.counter === "object") {

                // force params
                p.counter.url = encodeURIComponent(win.location);
                p.counter.id = btn.id;

                if (p.link) {
                    p.counter.link = encodeURIComponent(p.link);
                }

                p.counter.lang = p.lang;

                // transform to url
                var params = $wt.arrayToUrl(p.counter);

                // callback events and append info inside the button
                var showCounter = function(json, error) {

                    if (error) {
                        return;
                    }

                    // Counter is shown if no atleast parameter is provided or
                    // atleast is provided and total is greater than atleast value.

                    if (json.atleast === "" || (!isNaN(parseInt(json.atleast)) && parseInt(json.atleast) <= json.total)) {

                        var btnElt = document.getElementById(json.id);

                        if (btnElt) {

                            var cnt = doc.createElement("span");
                            cnt.className = "wtShareCounter";
                            cnt.innerHTML = "<b></b><span>" + json.total + "</span>";

                            btnElt.appendChild(cnt);

                        }

                    }

                };

                // send request
                $wt.jsonp($wt.sbkm._counter + "?" + params, showCounter, "js");

            }

            return btn;

        },

        // --------------------------------------------
        // GO TO LINK -> CHECK URL BEFORE EXECUTE
        // --------------------------------------------

        goLink: function(o, n, l) { // o = (this) obj src dom link, n = name


            var parent = o.parentNode.parentNode.parentNode,
                user_params = (parent.params) ? parent.params : $wt.sbkm.current.params,
                page_link = (user_params.link) ? user_params.link : window.location.href,
                page_link = (user_params.link === "noparams") ? (window.location.href).split("?")[0] : page_link,
                page_title = (user_params.title) ? user_params.title : document.title,
                link_href = l, // source href
                link_book = link_href,
                link_href = link_href.replace("__URL__", encodeURIComponent(page_link)).replace("__TITLE__", encodeURIComponent(page_title));

            o.href = "javascript:void(0)"; // browser hack

            // --------------------------------------------
            // SOURCE URL: TRANSFORM
            // --------------------------------------------

            if (n === "WordPress") {

                var wpId = prompt("WordPress ID?", "");
                link_href = link_href.replace(/__ID__/ig, encodeURIComponent(wpId));
                link_book = link_book.replace(/__ID__/ig, encodeURIComponent(wpId)); // here ^^

                if (!wpId || wpId === "") {
                    setTimeout(function() {
                        o.href = link_book;
                    }, 100);
                    return;
                }

            }

            // --------------------------------------------
            // SHARER PARAMS
            // --------------------------------------------

            var sharer = $wt.sbkm._sharer + "?";
            sharer += "action=" + ((user_params.stats === false) ? "do-not-log" : "log");
            sharer += "&plugin=bookmarks";
            sharer += "&name=" + encodeURIComponent(n);
            sharer += "&link=" + encodeURIComponent(page_link);
            sharer += "&title=" + encodeURIComponent(page_title);
            sharer += "&link_bookmark=" + encodeURIComponent(link_book);
            sharer += "&tag=" + ((user_params.counter.tag) ? encodeURIComponent(user_params.counter.tag) : "");
            sharer += "&seed=" + Math.random();

            if (n === "Twitter") {

                sharer += '&shorten_url=true';
                sharer += '&shorten_title_limit=90';
                sharer += ((user_params.via) ? "&options[twitter][via_handle]=" + user_params.via : "");

            }

            // --------------------------------------------
            // BEFORE SENDING
            // --------------------------------------------

            if (n === "E-mail") {

                function runMail() {
                    window.location = link_href;
                };

                var img = document.createElement("IMG");
                img.src = sharer;

                document.body.appendChild(img);

                img.onload = runMail;
                img.onerror = runMail;

            }
            else {

                window.location = sharer;

            }

            return false;

        },

        // --------------------------------------------
        // CREATE LINKS
        // --------------------------------------------

        getLinks: function(n, h) { // n = name, h = url

            var p = $wt.sbkm.current.params;

            // --------------------------------------------
            // LABEL EXCEPTION
            // --------------------------------------------

            var lab = (n === "E-mail") ? ($wt.label("sbkm", "email", p.lang) || n) : n;

            // --------------------------------------------
            // WITH OR WITHOUT ICON
            // --------------------------------------------

            var cls = (p.popup === false && p.icon === true) ? 'wtBtnOnlyIco' : 'wtShareLink';

            // --------------------------------------------
            // XHTML OUTPUT
            // --------------------------------------------

            cls += " wt_"+n.toLowerCase();

            var nh = h.replace("__URL__", encodeURIComponent(window.location.href)).replace("__TITLE__", encodeURIComponent(document.title));

            return '<li><a class="'+cls+'" href="'+nh+'" style="cursor:pointer" tabindex="0" title="'+lab+'" onclick="$wt.sbkm.goLink(this,\'' + n + '\',\''+h+'\'); return false;"><span class="wtIcon wtShareIcon wtShareIcon_' + (n.toLowerCase()) + '"></span>' + lab + '</a></li>';

        },

        // --------------------------------------------
        // Return the CSS class based from type
        // --------------------------------------------
        // j = $wt.sbkm.current
        // t = type -> "button", "list" or "popup"
        // --------------------------------------------

        getCSS: function(j, t) { // j = obj, t = type

            var c = j.params.css,
                l = {
                    "button": "wtShareButton",
                    "list": "wtShareList",
                    "popup": "wtSharePopup"
                };

            if (c) {
                if (c[t]) {
                    return c[t];
                }
            }

            return l[t];

        },

        // --------------------------------------------
        // Build (popup) header area with special SBKM button(s)
        // --------------------------------------------

        buildHeader: function(title) {

            var p = $wt.sbkm.current.params;
            var c = $wt.label("sbkm", "close", p.lang);
            var h = '<a title="'+c+'" class="wtPopupCloseBtn" href="javascript:$wt.pop.close()"><b>&times;</b><span>'+c+'</span></a>';
            h += title;

            return h;

        },

        // --------------------------------------------
        // Display or hide disclaimer text
        // --------------------------------------------

        toggleDisclaimer: function() {

            var d = $wt.sbkm.popup.footer;

            if (d.className.indexOf("wtPopupDisc") !== -1) {
                d.className = "wtPopupFooter";
            }
            else {
                d.className += " wtPopupDisc";
            }

        },

        // --------------------------------------------
        // ALL AVAILABLE LINKS BY NAME
        // --------------------------------------------

        links: {
            "E-mail": "mailto:?subject=__TITLE__&body=__URL__",
            "Facebook": "http://www.facebook.com/share.php?u=__URL__&t=__TITLE__", // -> ___SBKM_SHARE___/share.php?shareurl=[http://www.facebook.com/share.php?u=__URL__&t=__TITLE__]&stats=true
            "Twitter": "https://twitter.com/intent/tweet?url=__URL__&text=__TITLE__",
            "GooglePlus": "https://plus.google.com/share?url=__URL__&t=__TITLE__",
            "Google": "http://www.google.com/bookmarks/mark?op=edit&bkmk=__URL__&title=__TITLE__&annotation=",
            "Live": "https://profile.live.com/badge?url=__URL__&title=__TITLE__&description=&screenshot=&rss=",
            "Blogger": "http://www.blogger.com/blog_this.pyra?t=__TITLE__&u=__URL__&n=__TITLE__",
            "LinkedIn": "http://www.linkedin.com/shareArticle?mini=true&url=__URL__&title=__TITLE__&ro=false&summary=&source=",
            "Pocket": "https://getpocket.com/edit.php?url=__URL__&title=__TITLE__",
            "StumbleUpon": "http://www.stumbleupon.com/submit?url=__URL__&title=__TITLE__",
            "Tumblr": "http://www.tumblr.com/share?v=3&u=__URL__&t=__TITLE__&s=",
            "Pinterest": "http://www.pinterest.com/pin/create/button/?url=__URL__&media=http%3 A%2F%2Fec.europa.eu%2Fwel%2Ftemplate-2012%2Fimages%2Flogo%2Flogo_en.gif&description=__TITLE__",
            "Yammer": "https://www.yammer.com/home/bookmarklet?t=__TITLE__&u=__URL__",
            "MySpace": "http://www.myspace.com/Modules/PostTo/Pages/?u=__URL__&t=__TITLE__",
            "Bitly": "http://bit.ly/?url=__URL__",
            "Digg": "http://digg.com/submit?phase=2&url=__URL__&title=__TITLE__&bodytext=",
            "Technorati": "http://technorati.com/faves?sub=favthis&add=__URL__",
            "Delicious": "http://delicious.com/post?url=__URL__&title=__TITLE__&notes=",
            "Reddit": "http://reddit.com/submit?url=__URL__&title=__TITLE__",
            "Bebo": "http://bebo.com/c/share?Url=__URL__&Title=__TITLE__",
            "PrintFriendly": "http://www.printfriendly.com/printc?url=__URL__",
            "Viadeo": "http://www.viadeo.com/shareit/share/?url=__URL__&title=__TITLE__&encoding=UTF-8",
            "WordPress": "http://__ID__.wordpress.com/wp-admin/press-this.php?u=__URL__&t=__TITLE__&s=&v=2",
            "Typepad": "http://www.typepad.com/services/quickpost/post?v=2&qp_show=ac&qp_title=__TITLE__&qp_href=__URL__&qp_text=",
            "Netlog": "http://www.netlog.com/go/manage/links/?view=save&origin=external&url=__URL__&title=__TITLE__&description=",
            "Netvibes": "http://www.netvibes.com/share?title=__TITLE__&url=__URL__",
            "Gmail": "https://mail.google.com/mail/?view=cm&fs=1&tf=1&to=&su=__TITLE__&body=__URL__&zx=RANDOMCRAP&shva=1&disablechatbrowsercheck=1&ui=1",
            "YahooMail": "http://compose.mail.yahoo.com/?Subject=__TITLE__&body=__URL__",
            "Translate": "http://translate.google.com/translate?&u=__URL__&sl=&tl=",
            "Arto": "http://www.arto.com/section/linkshare/?lu=__URL__&ln=__TITLE__",
            "BlinkList": "http://www.blinklist.com/index.php?Action=Blink/addblink.php&Url=__URL__&Title=__TITLE__",
            //"Bloggy": "http://bloggy.se/home?status=__TITLE__ __URL__",
            "Blogmarks": "http://blogmarks.net/my/new.php?mini=1&simple=1&url=__URL__&title=__TITLE__",
            "Diigo": "http://www.diigo.com/post?url=__URL__&title=__TITLE__",
            "DZone": "http://www.dzone.com/links/add.html?url=__URL__&title=__TITLE__",
            "eKudos": "http://www.ekudos.nl/artikel/nieuw?url=__URL__&title=__TITLE__&desc=",
            "Fark": "http://cgi.fark.com/cgi/fark/farkit.pl?h=__TITLE__&u=__URL__",
            //"FriendFeed": "http://www.friendfeed.com/share?title=__TITLE__&link=__URL__",
            "HackerNews": "http://news.ycombinator.com/submitlink?u=__URL__&t=__TITLE__",
            "Haohao": "http://www.haohaoreport.com/submit.php?url=__URL__&title=__TITLE__",
            //"Hemidemi": "http://www.hemidemi.com/user_bookmark/new?title=__TITLE__&url=__URL__",
            "Kirtsy": "http://www.kirtsy.com/submit.php?url=__URL__",
            "LinkArena": "http://linkarena.com/bookmarks/addlink/?url=__URL__&title=__TITLE__",
            "Linkuj": "http://linkuj.cz/?id=linkuj&url=__URL__&title=__TITLE__&description=&imgsrc=",
            "Meneame": "http://meneame.net/submit.php?url=__URL__",
            "MisterWong": "http://www.mister-wong.com/addurl/?bm_url=__URL__&bm_description=__TITLE__&plugin=soc",
            //"MSNReporter": "http://reporter.nl.msn.com/?fn=contribute&Title=__TITLE__&URL=__URL__&cat_id=6&tag_id=31&Remark=",
            //"MyShare": "http://myshare.url.com.tw/index.php?func=newurl&url=__URL__&desc=__TITLE__",
            "N4G": "http://www.n4g.com/tips.aspx?url=__URL__&title=__TITLE__",
            "Netvouz": "http://www.netvouz.com/action/submitBookmark?url=__URL__&title=__TITLE__&popup=no",
            "NewsVine": "http://www.newsvine.com/_tools/seed&save?u=__URL__&h=__TITLE__",
            "NuJIJ": "http://nujij.nl/jij.lynkx?t=__TITLE__&u=__URL__&b=",
            "Oknotizie": "http://oknotizie.virgilio.it/post?title=__TITLE__&url=__URL__",
            "Pusha": "http://www.pusha.se/posta?url=__URL__&title=__TITLE__&description=",
            "Segnalo": "http://segnalo.alice.it/post.html.php?url=__URL__&title=__TITLE__",
            "Slashdot": "http://slashdot.org/bookmark.pl?title=__TITLE__&url=__URL__",
            "Sonico": "http://www.sonico.com/share.php?url=__URL__&title=__TITLE__",
            "StudiVZ": "http://www.studivz.net/Link/Selection/Url/?u=__URL__&desc=__TITLE__",
            "ThisNext": "http://www.thisnext.com/pick/new/submit/sociable/?url=__URL__&name=__TITLE__",
            "Tuenti": "http://www.tuenti.com/share?url=__URL__",
            //"Upnews": "http://www.upnews.it/submit?url=__URL__&title=__TITLE__",
            "Wists": "http://wists.com/r.php?r=__URL__&title=__TITLE__",
            "Wykop": "http://www.wykop.pl/dodaj?url=__URL__",
            "Xerpi": "http://www.xerpi.com/block/add_link_from_extension?url=__URL__&title=__TITLE__"

            //,"Evernote" : "http://www.evernote.com/clip.action?url=__URL__&title=__TITLE__"

        }

    };

})(window, document);/**
 * Created by jorgealves on 17/11/2015.
 */
